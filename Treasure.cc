#include "Treasure.h" 
#include <random>
#include <iostream>

char Treasure::charAt(int row, int col, int tick) {
    if (active && col == this->x && row == this->y) {
        return 'G';
    }
    return next->charAt(row, col, tick);
}

char Dragon_Hoard::charAt(int row, int col, int tick) {
    if (active && isGuarded && col == this->x && row == this->y) {
        if (next->charAt(row, col, tick) == '@') {
            return '@';
        } else {
            return 'G';
        }   
    }
    return next->charAt(row, col, tick);
}

Treasure::Treasure(AsciiArt *next, int x, int y, double val): Item{next, x, y, val}{}


void Treasure::applyEffect(Player *player) {
    player->addGold(getAmt());
    active = false;
    deleteItem(this);
    announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
}

Dragon_Hoard::Dragon_Hoard(AsciiArt *next, int x, int y): Treasure{next, x, y, 6},
                                                                isGuarded{true}{}

void Dragon_Hoard::applyEffect(Player *player) {
    if (!isGuarded) {
        player->addGold(getAmt());
        active = false;
        deleteItem(this);
        announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
    }
}

void Dragon_Hoard::unGuarded() {
    isGuarded = false;
}


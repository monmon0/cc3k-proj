#include "Treasure.h" 
#include <random>
#include <iostream>

char Treasure::charAt(int row, int col) {
    if (active && col == this->x && row == this->y) {
        return 'G';
    }
    return next->charAt(row, col);
}

Treasure::Treasure(AsciiArt *next, int x, int y, double val): Item{next, x, y, val}{}


void Treasure::applyEffect(Player *player) {
    player->addGold(getAmt());
    active = false;
    announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
}

bool Treasure::collectable() {}


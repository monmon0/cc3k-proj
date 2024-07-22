#include "Treasure.h" 
#include <random>
#include <iostream>

char Treasure::charAt(int x, int y, int tick) {
    if (active && x == this->x && y == this->y) {
        return 'G';
    }
    return next->charAt(x, y, tick);
}

Treasure::Treasure(AsciiArt *next, int x, int y, double val): Item{next, x, y, val}{}


void Treasure::applyEffect(Player *player) {
    // if (!isGuarded) {
        // std::cout << getAmt() << std::endl;
        player->addGold(getAmt());
        active = false;
        deleteItem(this);
        announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
    // }
}

Dragon_Hoard::Dragon_Hoard(AsciiArt *next, int x, int y, double val, Subject *dragon): 
                                                                Treasure{next, x, y, val},
                                                                isGuarded{true},
                                                                dragon{dragon}{
    dragon->attach(this);
}

void Dragon_Hoard::applyEffect(Player *player) {
    if (!isGuarded) {
        player->addGold(getAmt());
        active = false;
        deleteItem(this);
        announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
    }
}

void Dragon_Hoard::notify() {
    if (dragon->getState()) {
        isGuarded = false;
    }
}


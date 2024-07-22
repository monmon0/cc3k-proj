#include "Treasure.h" 
#include <random>
#include <iostream>

char Treasure::charAt(int x, int y, int tick) {
    if (active && x == this->x && y == this->y) {
        return 'G';
    }
    return next->charAt(x, y, tick);
}

Treasure::Treasure(AsciiArt *next, int x, int y, double val): Item{next, x, y, val}{
    addItem(x, y, this);
}


void Treasure::applyEffect(Player *player) {
    //if (!isGuarded) {
        // std::cout << getAmt() << std::endl;
        player->addGold(getAmt());
        active = false;
        deleteItem(this);
        announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
    //}
}



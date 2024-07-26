#include "Dragon_Hoard.h"

char Dragon_Hoard::charAt(int row, int col) {
    if (active && isGuarded && col == this->x && row == this->y) {
        if (next->charAt(row, col) == '@') {
            return '@';
        } else {
            return 'G';
        }   
    }
    return next->charAt(row, col);
}

Dragon_Hoard::Dragon_Hoard(AsciiArt *next, int x, int y): Treasure{next, x, y, 6},
                                                                isGuarded{true}{}

void Dragon_Hoard::applyEffect(Player *player) {
    if (!isGuarded) {
        player->addGold(getAmt());
        active = false;
        announcement = "PC obtained" + std::to_string(getAmt()) + "gold";
    }
}

void Dragon_Hoard::unGuarded() {
    isGuarded = false;
    active = true; 
}

bool Dragon_Hoard::collectable() {
    return !isGuarded;
}

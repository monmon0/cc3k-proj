#include "Potion.h"

Potion::Potion(AsciiArt *next, int x, int y, double amt, string name1): 
                                                        Item{next, x, y, amt}{ name = name1;}

char Potion::charAt(int row, int col) {
    if (active && col == this->x && row == this->y) {
        return 'P';
    }
    return next->charAt(row, col);
}

void Potion::undoEffect(Player *player) {}

#include "Potion.h"

Potion::Potion(AsciiArt *next, int x, int y, double amt, string name): 
                                                        Item{next, x, y, amt}, name{name}{}

char Potion::charAt(int row, int col) {
    if (active && col == this->x && row == this->y) {
        return 'P';
    }
    return next->charAt(row, col);
}

string Potion::getName() const {
    return name;
}

void Potion::undoEffect(Player *player) {}

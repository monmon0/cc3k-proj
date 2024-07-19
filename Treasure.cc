#include "Treasure.h" 

char Treasure::charAt(int x, int y, int tick) {
    if (x == this->x && y == this->y) {
        return 'G';
    }
    return next->charAt(x, y, tick);
}

Treasure::Treasure(AsciiArt *next, int x, int y, int val): Item{next, x, y, val}{}

void Treasure::applyEffect(Player *player) {
    player->addGold(getAmt());
}

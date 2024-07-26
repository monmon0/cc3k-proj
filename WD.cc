#include "WD.h"

WD::WD(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -5, name}{}

void WD::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    player->attach(this);
    active = false;
    player->changeDef(amt);
    announcement = "PC uses " + getName() + ". ";
}

void WD::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}

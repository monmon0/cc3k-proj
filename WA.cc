#include "WA.h"

WA::WA(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -5, name}{}

void WA::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    player->attach(this);
    active = false;
    player->changeAtk(amt);
    announcement = "PC uses " + getName() + ". ";
}

void WA::undoEffect(Player *player) {
    player->detach(this);
    player->changeAtk(-1 * amt);
}

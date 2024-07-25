#include "PH.h"

PH::PH(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -10, name}{}

void PH::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }

    if (player->getHp() >= amt) {
        player->changeHP(amt);
    } else {
        player->changeHP(-1 * player->getHp());
    }
    active = false;
    announcement = "PC uses " + getName() + ". ";
}

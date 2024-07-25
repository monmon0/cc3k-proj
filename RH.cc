#include "RH.h"

RH::RH(AsciiArt *next, int x, int y, string name) : 
                        Potion{next, x, y, 10, name}{
}

void RH::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    
    if (player->getHp() + amt <= player->getMaxHP()) {
        player->changeHP(amt);
    } else {
        player->changeHP(player->getMaxHP() - player->getHp());
    }
    active = false;
    announcement = "PC uses " + getName() + ". ";
}

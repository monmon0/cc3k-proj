#include "Potion.h"

Potion::Potion(AsciiArt *next, int x, int y, double amt, string name): 
                                                        Item{next, x, y, amt}, name{name}{}

char Potion::charAt(int row, int col, int tick) {
    if (active && col == this->x && row == this->y) {
        return 'P';
    }
    return next->charAt(row, col, tick);
}

string Potion::getName() const {
    return name;
}

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

BA::BA(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, 5, name}{}

void BA::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    player->attach(this);
    active = false;
    player->changeAtk(amt);
    announcement = "PC uses " + getName() + ". ";
}

void BA::undoEffect(Player *player) {
    player->detach(this);
    player->changeAtk(-1 * amt);
}

BD::BD(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, 5, name}{}

void BD::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    player->attach(this);
    active = false;
    player->changeDef(amt);
    announcement = "PC uses " + getName() + ". ";
}

void BD::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}

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

WA::WA(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -5, name}{}

void WA::applyEffect(Player *player) {
    if (player->getRace() == 'd') {
        amt *= 1.5;
    }
    player->attach(this);
    active = false;
    player->changeDef(amt);
    announcement = "PC uses " + getName() + ". ";
}

void WA::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}

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


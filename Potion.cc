#include "Potion.h"

Potion::Potion(AsciiArt *next, int x, int y, int amt, string name): 
                                                        Item{next, x, y, amt}, name{name}{
    addItem(x, y, this);
}

char Potion::charAt(int x, int y, int tick) {
    if (x == this->x && y == this->y) {
        return 'P';
    }
    return next->charAt(x, y, tick);
}


RH::RH(AsciiArt *next, int x, int y, string name) : 
                        Potion{next, x, y, 10, name}{
}

void RH::applyEffect(Player *player) {
    if (player->getHp() + amt <= player->getMaxHP()) {
        player->changeHP(amt);
    } else {
        player->changeHP(player->getMaxHP() - player->getHp());
    }
    deleteItem(this);
}

BA::BA(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, 5, name}{}

void BA::applyEffect(Player *player) {
    player->attach(this);
    deleteItem(this);
    player->changeAtk(amt);
}

void BA::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeAtk(-1 * amt);
}

BD::BD(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, 5, name}{}

void BD::applyEffect(Player *player) {
    player->attach(this);
    deleteItem(this);
    player->changeDef(amt);
}

void BD::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeDef(-1 * amt);
}

PH::PH(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -10, name}{}

void PH::applyEffect(Player *player) {
    if (player->getHp() >= amt) {
        player->changeHP(amt);
    } else {
        player->changeHP(-1 * player->getHp());
    }
    deleteItem(this);
}

WA::WA(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -5, name}{}

void WA::applyEffect(Player *player) {
    player->attach(this);
    deleteItem(this);
    player->changeDef(amt);
}

void WA::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeDef(-1 * amt);
}

WD::WD(AsciiArt *next, int x, int y, string name) :
                        Potion{next, x, y, -5, name}{}

void WD::applyEffect(Player *player) {
    player->attach(this);
    deleteItem(this);
    player->changeDef(amt);
}

void WD::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeDef(-1 * amt);
}


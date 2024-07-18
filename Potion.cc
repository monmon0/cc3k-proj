#include "Potion.h"
#include "PotionMap.h"

Potion::Potion(AsciiArt *next, int x, int y, string name, int amt): 
                                                        Decorator{next}, 
                                                        x{x}, 
                                                        y{y}, 
                                                        name{name},
                                                        amt{amt}{}

char Potion::charAt(int x, int y, int tick) {
    if (x == this->x && y == this->y) {
        return 'P';
    }
    return next->charAt(x, y, tick);
}

void Potion::notify(Player *player, int x, int y) {
    if (x == this->x && y == this->y) {
        applyEffect(player);
    }
}

RH::RH(AsciiArt *next, int x, int y, string name, int amt) : 
                        Potion{next, x, y, name, 10}{
    addPotion(x, y, this);
}

void RH::applyEffect(Player *player) {
    if (player->getHP() + amt <= player->getMax()) {
        player->changeHP(amt);
    }
}

BA::BA(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, 5}{
    addPotion(x, y, this);                        
}

void BA::applyEffect(Player *player) {
    player->attach(this);
    player->changeAtk(amt);
}

void BA::undoEffect(Player *player) {
    player->detach(this);
    player->changeAtk(-1 * amt);
}

BD::BD(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, 5}{
    addPotion(x, y, this);                        
}

void BD::applyEffect(Player *player) {
    player->attach(this);
    player->changeDef(amt);
}

void BD::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}

PH::PH(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, -10}{
    addPotion(x, y, this);                        
}

void PH::applyEffect(Player *player) {
    if (player->getHP() >= amt) {
        player->changeHP(amt);
    }
}

WA::WA(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, -5}{
    addPotion(x, y, this);                        
}

void WA::applyEffect(Player *player) {
    player->attach(this);
    player->changeDef(amt);
}

void WA::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}

WD::WD(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, -5}{}

void WD::applyEffect(Player *player) {
    player->attach(this);
    player->changeDef(amt);
}

void WD::undoEffect(Player *player) {
    player->detach(this);
    player->changeDef(-1 * amt);
}


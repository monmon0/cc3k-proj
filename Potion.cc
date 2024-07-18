#include "Potion.h"

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

int Potion::getAmt() {
    return amt;
}

void Potion::addPotion(int x, int y, Potion* potion) {
    pMap[make_pair(x, y)] = potion;
}

Potion *Potion::getPotion(int x, int y) {
    for (auto &p : pMap) {
        if (p.first == make_pair(x, y)) {
            return p.second;
        }
    }
    return nullptr;
}

void Potion::deleteAll() {
    for (auto &p : pMap) {
        delete p.second();
    }
}

void Potion::deletePotion(Potion *potion) {
    for (auto it = pMap.begin(); it != pMap.end(); ++it) {
        if (it->second == potion) {
            pMap.erase(it);
            break;
        }
    }
}

RH::RH(AsciiArt *next, int x, int y, string name, int amt) : 
                        Potion{next, x, y, name, 10}{
    addPotion(x, y, this);
}

void RH::applyEffect(Player *player) {
    player->changeHP(amt);
}

BA::BA(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, 5}{}

void BA::applyEffect(Player *player) {
    player->attach(this);
    deletePotion(this);
    player->changeAtk(amt);
}

void BA::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeAtk(-1 * amt);
}

BD::BD(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, 5}{
    addPotion(x, y, this);                        
}

void BD::applyEffect(Player *player) {
    player->attach(this);
    deletePotion(this);
    player->changeDef(amt);
}

void BD::undoEffect(Player *player) {
    player->detach(this);
    delete this;
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
    deletePotion(this);
}

WA::WA(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, -5}{
    addPotion(x, y, this);
}

void WA::applyEffect(Player *player) {
    player->attach(this);
    deletePotion(this);
    player->changeDef(amt);
}

void WA::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeDef(-1 * amt);
}

WD::WD(AsciiArt *next, int x, int y, string name, int amt) :
                        Potion{next, x, y, name, -5}{
    addPotion(x, y, this);                        
}

void WD::applyEffect(Player *player) {
    player->attach(this);
    deletePotion(this);
    player->changeDef(amt);
}

void WD::undoEffect(Player *player) {
    player->detach(this);
    delete this;
    player->changeDef(-1 * amt);
}


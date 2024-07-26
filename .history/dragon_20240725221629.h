#ifndef DRAGON_H
#define DRAGON_H

#include "Enemies.h"
#include "Treasure.h"
#include "itemFactory.h"

class Dragon_Hoard;

class Dragon : public Enemy {
    Dragon_Hoard *dh;
public:
    Dragon(AsciiArt *next, int xCoord, int yCoord, Dragon_Hoard *dh); 
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

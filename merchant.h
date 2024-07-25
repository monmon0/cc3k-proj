#ifndef MERCHANT_H
#define MERCHANT_H

#include "Enemies.h"

class Merchant : public Enemy {
public:
    Merchant(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

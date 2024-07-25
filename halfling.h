#ifndef HALFLING_H
#define HALFLING_H

#include "Enemies.h"

class Halfling : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

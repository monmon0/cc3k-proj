#ifndef HUMAN_H
#define HUMAN_H

#include "Enemies.h"

class Human : public Enemy {
public:
    Human(AsciiArt *next, int xCoord, int yCoord); 
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

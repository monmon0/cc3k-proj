#ifndef ORC_H
#define ORC_H

#include "Enemies.h"

class Orc : public Enemy {
public:
    Orc(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

#ifndef DWARF_H
#define DWARF_H

#include "Enemies.h"

class Dwarf : public Enemy {
public:
    Dwarf(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

#ifndef ELF_H
#define ELF_H

#include "Enemies.h"

class Elf : public Enemy {
public:
    Elf(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif

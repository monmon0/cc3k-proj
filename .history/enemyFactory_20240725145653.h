#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Potion.h"
#include "Treasure.h"

class EnemyFactory {
    public:
        enum Type {HUMAN, DWARF, ELF, ORC, MERCHANT, HALFLING : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Dragon_Hoard;

class Dragon};
        static Item *createItem(Type type, AsciiArt *next, int x, int y);
};

#endif

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Enemy.h"
#include "treasure.h"

class EnemyFactory {
    public:
        enum Type {HUMAN, DWARF, ELF, ORC, MERCHANT, HALFLING, DRAGON};
        static Enemy *createEnemy(Type type, AsciiArt *next, int x, int y);
};

#endif

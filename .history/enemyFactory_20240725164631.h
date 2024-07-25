#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <memory>
#include "Enemies.h"

class EnemyFactory {
    public:
        enum Type {HUMAN, DWARF, ELF, ORC, MERCHANT, HALFLING};
        static Enemy *createEnemy(Type type, AsciiArt *next, int x, int y);
};

>>>>>>> Stashed changes
#endif

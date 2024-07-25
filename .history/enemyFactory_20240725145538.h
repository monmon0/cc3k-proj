#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Potion.h"
#include "Treasure.h"

class EnemyFactory {
    public:
        enum Type {POTION_RH, POTION_BA, POTION_BD, POTION_PH, POTION_WA, POTION_WD, 
                    GOLD_NORMAL, GOLD_SMALL, GOLD_MERCHANT, GOLD_DRAGON};
        static Item *createItem(Type type, AsciiArt *next, int x, int y);
};

#endif

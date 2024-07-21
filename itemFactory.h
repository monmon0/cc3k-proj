#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Potion.h"
#include "Treasure.h"

class ItemFactory {
    public:
        enum Type {POTION_RH, POTION_BA, POTION_BD, POTION_PH, POTION_WA, POTION_WD, 
                    GOLD_SMALL, GOLD_NORMAL, GOLD_MERCHANT, GOLD_DRAGON};
        static Item *createItem(Type type, AsciiArt *next, int x, int y);
};

#endif

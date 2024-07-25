#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include "item.h"
#include <map>
#include <utility>

class Treasure: public Item {
    public:
        Treasure(AsciiArt *next, int x, int y, double val);
        char charAt(int row, int col) override;
        void applyEffect(Player *player) override;
};

#endif

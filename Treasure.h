#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include "item.h"
#include <map>
#include <utility>

class Player;

class Treasure: public Item {
    public:
        Treasure(AsciiArt *next, int x, int y, double val);
        char charAt(int x, int y, int tick) override;
        void applyEffect(Player *player) override;
};

#endif

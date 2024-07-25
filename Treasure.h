#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include "Enemies.h"
#include "item.h"
#include "Observer.h"
#include <map>
#include <utility>

class Player;
class Enemies;

class Treasure: public Item {
    public:
        Treasure(AsciiArt *next, int x, int y, double val);
        char charAt(int row, int col) override;
        void applyEffect(Player *player) override;
};

#endif

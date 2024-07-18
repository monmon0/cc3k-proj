#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"
#include "Observer.h"
#include "PotionDecorator.h"
#include "Players.h"

class Treasure: public Observer {
    int x;
    int y;
    int val;
    public:
        char charAt(int x, int y, int tick) const;
        int getVal() const;
}

#endif

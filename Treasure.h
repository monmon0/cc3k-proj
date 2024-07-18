#ifndef TREASURE_H
#define TREASURE_H
#include "Observer.h"
#include "Players.h"
#include <map>
#include <utility>

class Treasure {
    static inline map<pair<int, int>, Potion *> gMap;
    protected:
        int x;
        int y;
        int val;
    public:
        Treasure(int x, int y, int val);
        char charAt(int x, int y, int tick) const;
        int getVal() const;
        static void deleteTreasure(Treasure *tr);
        static void addTreasure(int x, int y, Treasure *tr);
        static void deleteAllT();
};

#endif

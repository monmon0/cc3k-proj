#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include <map>
#include <utility>

class Treasure: public Decorator {
    static inline map<pair<int, int>, Treasure *> gMap;
    protected:
        int x;
        int y;
        int val;
    public:
        <<<<<<< HEAD
                Treasure(AsciiArt *art, int x, int y, int val);
        =======
                Treasure(AsciiArt *next, int x, int y, int val);
        >>>>>>> ee97655c5ebad27c50558f4eba64aab97d4a9747
        char charAt(int x, int y, int tick) override;
        int getVal() const;
        static void deleteTreasure(Treasure *tr);
        static void addTreasure(int x, int y, Treasure *tr);
        static void deleteAllT();
};

#endif

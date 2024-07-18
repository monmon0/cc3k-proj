#ifndef TREASURE_H
#define TREASURE_H
#include "Observer.h"
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
>>>>>>> 2587b65e66e9d568f90254e623f57e55cc6ce00b
        char charAt(int x, int y, int tick) override;
        int getVal() const;
        static void deleteTreasure(Treasure *tr);
        static void addTreasure(int x, int y, Treasure *tr);
        static void deleteAllT();
};

#endif

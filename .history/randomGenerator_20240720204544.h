#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include "dungeon.h"
#include "PRNG.h"

#include <string>
#include <unistd.h>	// getpid

class Dungeon;

class Random {
    int x = 0, y = 0;
    Dungeon * curr;

    public:
        Random(Dungeon * curr): curr{curr} {};

        int new_x, new_y;

        int giveRandomInt(); 
        void setPos(); 
        int getX() const { return x; };
        int getY() const { return y; };
};

#endif

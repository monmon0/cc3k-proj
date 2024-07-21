#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include "dungeon.h"
#include "PRNG.h"

#include <string>
#include <unistd.h>	// getpid

class Dungeon;

class RandomPos {
    int x = 0, y = 0;
    Dungeon * curr;

    public:
        RandomPos(Dungeon * curr): curr{curr} {};

        int new_x, new_y;

        int 
        void setPos(); 
        int getX() const { return x; };
        int getY() const { return y; };
};

#endif

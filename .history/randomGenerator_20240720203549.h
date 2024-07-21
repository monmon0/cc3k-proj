#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include "dungeon.h"
#include "PRNG.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>	// getpid

class Dungeon;

class RandomPos {
    int x = 0, y = 0;
    Dungeon * curr;

    public:
        RandomPos(Dungeon * curr): curr{curr} {
            std::srand(std::time(0));
        };

        int new_x, new_y;

        void setPos(); 
        int getX() const { return x; };
        int getY() const { return y; };
};

#endif

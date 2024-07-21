#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include "dungeon.h"
#include "PRNG.h"

#include <string>
#include <unistd.h>	// getpid

class Dungeon;

class CheckCoord {
    int x = 0, y = 0;
    Dungeon * curr;

    uint32_t seed = getpid();  
    PRNG prng; 

    public:
        CheckCoord(Dungeon * curr, uint32_t seed): curr{curr} {};

        int new_x, new_y;

        int giveRandomInt(int i, uint32_t seed); 
        void setPos(uint32_t seed); 
        int getX() const { return x; };
        int getY() const { return y; };
};

#endif

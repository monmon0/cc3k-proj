#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include "dungeon.h"
#include "PRNG.h"

#include <string>
#include <unistd.h>	// getpid

class Dungeon;

class CheckCoord {
    int x = 1, y = 1; 
    int chamber = 0; 
    Dungeon * curr;
    int new_x, new_y;

    uint32_t seed = getpid();  
    PRNG prng; 

    public:
        CheckCoord(Dungeon * curr, uint32_t seed): curr{curr}, prng{seed} {};
        int giveRandomInt(int i); 
        void setPos(); 
        void setPosStair(int PCChamber); 
        int getX() const { return x; };
        int getY() const { return y; };
        int getChamber() const;
};

#endif

#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include <stdlib.h>
#include "dungeon.h"
#include <cstdlib>
#include <ctime>
#include <string>

class RandomPos {
    int x = 0, y = 0;

    public:
        RandomPos() {
            std::srand(std::time(0));
        };

        int new_x, new_y;

        void setPos(); 
        int getX() const { return x; };
        int getY() const { return y; };
};

#endif

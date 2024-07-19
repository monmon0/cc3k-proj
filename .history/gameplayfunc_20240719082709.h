#ifndef GAME_PLAY_FUNC_H
#define GAME_PLAY_FUNC_H
#include <stdlib.h>
#include "asciiart.h"
#include <cstdlib>
#include <ctime>
#include <string>

class RandomPos {
    int x = 0, y = 0;
    AsciiArt * curr;

    public:
        RandomPos(AsciiArt * curr): curr{curr} {
            std::srand(std::time(0));
        };

        int new_x, new_y;

        void setPos() {}; 

        int getX() {return x;};
        int getY() {return y;};
};

#endif

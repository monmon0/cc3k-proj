#ifndef SHADE_H
#define SHADE_H

#include "Players.h"

class Shade : public Player {
    public:
        Shade(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location):
            Player(next, race, x, y, hp, atk, def, location) {
            announcement = "Player chooses Shade.";
           };
};


#endif // SHADE_H

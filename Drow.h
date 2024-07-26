#ifndef DROW_H
#define DROW_H

#include "Players.h"

class Drow : public Player {
    public:
        Drow(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location):
           Player(next, race, x, y, hp, atk, def, location) {
            announcement = "Player chooses Drow.";
           };
};
#endif // DROW_H

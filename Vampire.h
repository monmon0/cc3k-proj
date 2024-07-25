#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Players.h"

class Vampire : public Player {
    public:
        Vampire(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location):
           Player(next, race, x, y, hp, atk, def, location)  {
            announcement = "Player chooses Vampire.";
           };
};

#endif // VAMPIRE_H
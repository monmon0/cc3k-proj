#ifndef GOBLIN_H
#define GOBLIN_H

#include "Players.h"

class Goblin : public Player {
    public:
        Goblin(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location):
           Player(next, race, x, y, hp, atk, def, location) {
            announcement = "Player chooses Goblin.";
           };
};


#endif // GOBLIN_H
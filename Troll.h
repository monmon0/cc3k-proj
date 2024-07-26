#ifndef TROLL_H
#define TROLL_H

#include "Players.h"

class Troll : public Player {
    public:
        Troll(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location):
           Player(next, race, x, y, hp, atk, def, location)  {
                announcement = "Player chooses Troll.";
            };
};

#endif // TROLL_H

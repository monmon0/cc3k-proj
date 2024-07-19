#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "asciiart.h"
#include "Enemies.h"
#include "decorator.h"
#include "dungeon.h"
#include "Potion.h"
#include "Treasure.h"
#include "gameplayfunc.h"
#include <algorithm>

If rand() is giving you the same number each time it's called within a loop, it is likely because the random number generator has not been properly seeded. In C++, the function rand() generates pseudo-random numbers and will produce the same sequence of results if it is always seeded with the same value.

By default, if you do not seed the random number generator, it behaves as if it was seeded with 1 every time your program runs. To get different sequences of random numbers on different runs, you need to seed it with a different value each time. The most common way to do this is by using the current time, as it changes every second.

Here’s how you can properly seed rand() using srand() based on the current time:

cpp
Copy code
#include <cstdlib>  // For rand() and srand()
#include <ctime>
#include "dungeon.h"
#include <memory>
#include <string>

class PlayGame {
    Dungeon * d;
    Enemy * first_E;
    Potion * first_P;

    public:
        PlayGame(Dungeon * d);
        ~PlayGame() = default; 
        void spawnEnemies();
        void spawnPotions();
        // void spawnTreasure();
        void play();
        void end();
        void levelUp(Player * p);
        void destroyPotions();
        // destroyEnemies();
        // destroyTreasure();
        void restart(Player * p);
        
};

#endif

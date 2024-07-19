#ifndef PLAYGAME_H
#define PLAYGAME_H
<<<<<<< HEAD
class PlayGame {
    
    
}
=======
#include "asciiart.h"
#include "Enemies.h"
#include "dungeon.h"
#include "Potion.h"
#include "Treasure.h"
#include "gameplayfunc.h"
#include <algorithm>
#include <random>
#include "dungeon.h"
#include <memory>
#include <string>

class PlayGame {
    Dungeon * d;
    public:
        PlayGame(Dungeon *curr);
        ~PlayGame() = default; 
        void spawnEnemies();
        void spawnPotions();
        void spawnTreasure();
        void play();
        void end();
        void levelUp(int x, int y);
};
>>>>>>> ee97655c5ebad27c50558f4eba64aab97d4a9747

#endif

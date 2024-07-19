#ifndef PLAYGAME_H
#define PLAYGAME_H
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

#endif

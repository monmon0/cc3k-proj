#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "asciiart.h"
#include "Enemies.h"
#include "Potion.h"
#include "Treasure.h"
#include "gameplayfunc.h"
#include <algorithm>
#include <random>
#include <memory>
#include <string>

class PlayGame {
    AsciiArt *curr;
    public:
        PlayGame(AsciiArt *curr);
        ~PlayGame() = default; 
        void spawnEnemies();
        void spawnPotions();
        void play();
        void end();
        void spawnTreasure();
        void levelUp();
};

#endif

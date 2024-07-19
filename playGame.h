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
#include <random>
#include "dungeon.h"
#include <memory>
#include <string>

class PlayGame {
    Dungeon * d;
    Enemy * first_E;
    Potion * first_P;

    public:
        PlayGame(Dungeon * d);
        ~PlayGame() {delete d; delete first_E; delete first_P;}; 
        void spawnEnemies();
        void spawnPotions();
        void spawnTreasure();
        void play();
        void end();
        void levelUp(Player * p);
        void destroyPotions();
        // destroyEnemies();
        // destroyTreasure();
        
};

#endif

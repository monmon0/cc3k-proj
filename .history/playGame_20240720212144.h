#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "asciiart.h"
#include "Enemies.h"
#include "decorator.h"
#include "dungeon.h"
#include "Potion.h"
#include "Treasure.h"
#include "randomGenerator.h"
#include <algorithm>
#include <cstdlib> 
#include <ctime>
#include "dungeon.h"
#include <memory>
#include <string>
#include <vector>

class PlayGame {

    Dungeon * d;
    Enemy * first_E;
    Potion * first_P;
    std::vector<Enemy *> eVec;


    public:
        PlayGame(Dungeon * d);
        ~PlayGame() = default; 
        void play();
        void end(); 

        bool checkCoord(int x, int y); 

        void spawnEnemies();
        // destroyEnemies();
        void attackOrMove(Player &pc); // take it in yourself  
        bool defeatEnemies(int x, int y, int PCAtk, std::string dir); // subtract hp, return whether the pc has a lower success beat rate 

        void spawnPotions();
        void destroyPotions();

        // void spawnTreasure();
        // destroyTreasure();

        void levelUp(Player * p);
        
        void restart(Player * p);
        
};

#endif

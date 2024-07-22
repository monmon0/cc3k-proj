#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "asciiart.h"
#include "Enemies.h"
#include "staircase.h"
#include "decorator.h"
#include "dungeon.h"
#include "Potion.h"
#include "Treasure.h"
#include "itemFactory.h"
#include "checkCoord.h"
#include <algorithm>
#include <cstdlib> 
#include <ctime>
#include "dungeon.h"
#include "Players.h"
#include <memory>
#include <string>
#include <vector>

class PlayGame {

    Dungeon * d;
    Enemy * first_E;
    Item * first_P;
    Item * first_T;
    Player *p = nullptr;
    std::vector<Enemy *> eVec;


    public:
        PlayGame(Dungeon * d);
        ~PlayGame() = default; 
        void play();
        void end(); 

        bool checkCoord(int x, int y); 

        void spawnStaircase(uint32_t seed); 

        void spawnPotions(uint32_t seed);
        void destroyPotions();

        void spawnEnemies(uint32_t seed);
        void destroyEnemies();
        void fPressed(); 
        void deadOrQuit();
        void attackOrMove(); 
        void defeatEnemies(int x, int y, std::string dir); 

        void spawnTreasure(uint32_t seed);
        void destroyTreasure();

        void levelUp();
        void restart(Player * p);
        void spawnPlayer(Player * p, std::string command);
        // void sendAnnouncement();
        
};

#endif

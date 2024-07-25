#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "Enemies.h"
#include "staircase.h"
#include "decorator.h"
#include "dungeon.h"
#include "Potion.h"
#include "Treasure.h"
#include "itemFactory.h"
#include "enemyFactory.h"
#include "checkCoord.h"
#include "dungeon.h"
#include "Players.h"
#include "blank.h"

#include <algorithm>
#include <cstdlib> 
#include <ctime>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <map>

class Blank;

class PlayGame {

    Dungeon * d;
    Player *p = nullptr;
    std::vector<Enemy *> eVec;
    std::map<int, std::pair<int, int>> eMap; 
    Staircase * sc;

    public:
        PlayGame(Dungeon * d);
        ~PlayGame() = default; 
        void play();
        void play(Blank *map);
        void end(); 
        bool checkCoord(int x, int y); 
        void attachPC(Player * pc) {p = pc;}
        void spawn(Blank *map); 
        void spawnStaircase(uint32_t seed); 
        void spawnPotions(uint32_t seed);
        void spawnEnemies(uint32_t seed);
        void fPressed(); 
        void deadOrQuit();
        void attackOrMove(); 
        void defeatEnemies(int x, int y, std::string dir); 
        void spawnTreasure(uint32_t seed);
        void levelUp();
        void restart();
};

#endif

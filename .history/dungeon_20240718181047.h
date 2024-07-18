#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Players.h"
#include "Enemies.h"

class AsciiArt;

class Dungeon : public EnemyFactory {
    int rows = 30, cols = 79, ticks = 0;
    std::ostream &out = std::cout;          
    AsciiArt *thePicture;             
    std::string action = "";
    std::vector<std::unique_ptr<Enemy>> enemies; 

public:
    explicit Dungeon(AsciiArt *picture): thePicture{picture} {}

    AsciiArt *&picture() { return thePicture; }
    void render(Player * p);
    void reset();
    void setAction(std::string a) {
        action += a;
    }
    void clearAction() { action = "";}
    void spawnEnemies();

    ~Dungeon();
};

#endif // DUNGEON_H

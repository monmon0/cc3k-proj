#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Players.h"
#include "Enemies.h"

class Enemy;

class Dungeon {
    int rows = 30, cols = 79, ticks = 0;
    std::ostream &out = std::cout;          
    AsciiArt *thePicture;             
    std::string action = "";
    int floor = 1;

public:
    explicit Dungeon(AsciiArt *picture): thePicture{picture} {}

    AsciiArt *&picture() { return thePicture; }
    void render(Player * p);
    void reset();
    void setAction(std::string a) { action += a;}
    void clearAction() { action = "";}
    void levelUp() { floor++;}

    ~Dungeon();
};

#endif // DUNGEON_H

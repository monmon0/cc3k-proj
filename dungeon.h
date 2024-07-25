#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Players.h"
#include "Enemies.h"
#include <algorithm>
#include <iostream>
#include <string>


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
    void setAction(std::string a);
    void clearAction();
    void levelUp();
    void resetLevel();
    int getLevel();

    ~Dungeon();
};

#endif // DUNGEON_H

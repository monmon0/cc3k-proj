#include <iostream>
#include <vector>
#include <memory>   // For std::unique_ptr
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "Players.h"
// #include "enemies.h"
// #include "enemyFactory.h"
#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    // std::string command;
    Player * pc =  new Player{'s', s.picture(), 4, 6, 10, 10, 10};

    s.picture() = pc;
    s.render();

    pc->move("ea", 1);
    s.render();
    pc->move("so", 1);
    s.render();

    // Clean up

}
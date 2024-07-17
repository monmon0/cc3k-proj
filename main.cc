#include <iostream>
#include <vector>

#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "players.h"

#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    // std::string command;
    Player *pc =  new Player{'s', s.picture()};
    s.picture() = pc;


    pc->move("ea", 1);
    pc->move("ea", 1);
    // player.move("no");
    s.render();
}
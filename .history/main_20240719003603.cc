#include <iostream>
#include <vector>
#include <memory>   
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "Players.h"
#include "Enemies.h"
#include "playGame.h"
#include "gameplayfunc.h"

#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;
    Dungeon s{canvas};


    RandomPos r_pos = RandomPos(s.picture());
    r_pos.setPos();

    PlayGame current_game{s.picture()};

    std::string dir1 = "so";
    std::string dir2 = "ea";
    // std::string command;
    Player * pc =  new Vampire{s.picture(), 't', 5, 4, 10, 10, 10};
    s.picture() = pc;
    s.render(pc);
    Enemy * pc =  new Human{s.picture(), 't', 5, 4, 10, 10, 10};
    s.picture() = pc;
    s.render(pc);

    current_game.spawnEnemies();
    // current_game.spawnPotions();

    pc->move("we", s.picture());
    pc->move("ea", s.picture());

    // s.setAction(pc->getAnnouncement());

    s.render(pc);
    // Clean up

}

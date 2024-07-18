#include <iostream>
#include <vector>
#include <memory>   
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "Players.h"
#include "Enemies.h"
#include "gameplayfunc.h"
// #include "enemyFactory.h"
#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    RandomPos r_pos = RandomPos(s.picture());
    r_pos.setPos();

    // std::cout << new_x << " " << new_y << std::endl;

    std::string dir1 = "so";
    std::string dir2 = "ea";
    // std::string command;c
    Player * pc =  new Vampire{'t', s.picture(), r_pos.getX(), r_pos.getY(), 10, 10, 10};
    
    s.picture() = pc;
    s.render(pc);
    s.render(pc);

    pc->move("we", s.picture());
    pc->move("ea", s.picture());

    s.setAction(pc->getAnnouncement());

    s.render(pc);
    // Clean up

}

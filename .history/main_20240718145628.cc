#include <iostream>
#include <vector>
#include <memory>   
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "Players.h"
#include "Enemies.h"
#include "enemyFactory.h"
#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    std::string dir1 = "so";
    std::string dir2 = "ea";
    // std::string command;
    Player * pc =  new Troll{'t', s.picture(), 4, 6, 10, 10, 10};
    
    s.picture() = pc;
    s.render(pc);
    Human * en = new Human(s.picture(), 3, 6); 
    s.picture() = en;
    s.render(pc);

    pc->move("we");

    s.setAction(pc->getAnnouncement());

    s.render(pc);

    // for (int i = 0; i < 9; i++){
    //     pc->move(dir2);
    //     // wrap this around after
    //     s.setAction(pc->getAnnouncement());
    //     s.render(pc);
    //     s.clearAction();
    // }

    // for (int i = 0; i < 10; i++) {
    //     pc->move(dir1);
    //      // wrap this around after
    //     s.setAction(pc->getAnnouncement());
    //     s.render(pc);
    //     s.clearAction();
    // }

    // Clean up

}
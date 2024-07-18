#include <iostream>
#include <vector>
#include <memory>   // For std::unique_ptr
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "Players.h"
#include "Enemies.h"
// #include "enemyFactory.h"
#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    std::string dir1 = "so";
    std::string dir2 = "ea";

    Human * en = new Human(s.picture(), 3, 3); 
    s.picture() = en;

    // std::string command;
    Player * pc =  new Player{'s', s.picture(), 4, 6, 10, 10, 10};

    s.picture() = pc;
    s.render(pc);

    for (int i = 0; i < 9; i++){
        pc->move(dir2);
        s.setAction("PC moves " + dir1 + ". ");
        s.setAction("PC wanna cry ");
        s.render(pc);
        s.clearAction();
    }


    for (int i = 0; i < 10; i++) {
        pc->move(dir1);
        s.setAction("PC moves " + dir1 + ". ");
        s.setAction("PC wanna cry ");
        s.render(pc);
        s.clearAction();
    }

    // Clean up

}
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
    // creating new Dungeon
    AsciiArt *floor = new Blank;
    Dungeon s{floor};
    PlayGame current_game{&s};
    std::string command;

    Player * pc = new Vampire{s.picture(), 't', 4, 6, 10, 10, 10};
    s.picture() = pc;

    while (std::cin >> command) {
        s.clearAction();
        //  s, d, v, g, t:
        if (command == "s" || command == "d" ||command == "v" 
        || command == "g" || command == "t") {
            // set races
            
            // start game, spawn enemies, spawn potions
            current_game.play();
        
        } else if (command == "no" || command == "so" || command == "ea" 
                || command == "we" || command == "ne" || command == "nw" 
                || command == "se" || command =="sw") {

            pc->move(command, s.picture());

        } else if (command == "u" ) {
            std::string dir;
            std::cin >> dir;
            // use potion

        } else if (command == "a" ) {
            std::string dir;
            std::cin >> dir;
            // attack enemies

        } else if (command == "lu") {
            current_game.levelUp(pc->getX(), pc->getY());
        }
        s.setAction(pc->getAnnouncement());
        s.render(pc);
    }
}

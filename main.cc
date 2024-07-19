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
    std::string command;

    Player * pc = new Vampire{s.picture(), 't', 4, 6, 10, 10, 10};
    PlayGame current_game{&s}; 
    s.render(pc);
    s.picture() = pc;


    while (std::cin >> command) {
        s.clearAction();
        //  s, d, v, g, t:
        if (command == "s" || command == "d" ||command == "v" 
        || command == "g" || command == "t") {
            // set races
            
            // start game, spawn enemies, spawn potions
            current_game.play();
            // s.picture() = current_game.getGameSpawn();
            s.render(pc);

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

        } 
        s.setAction(pc->getAnnouncement());
        s.render(pc);
    }
}

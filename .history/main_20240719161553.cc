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

class Blank;


int main() {
    // creating new Dungeon
    Blank *floor = new Blank("map.txt");
    Dungeon s{floor};
    PlayGame curr_g{&s};
    std::string command;
    Player * pc;

    // --------------- START GAME ------------------------- //
    std::cout << "                                              " << std::endl
              << "                                              " << std::endl
              << "WELCOME to SYLVIA, EASON & MONICA CC3k DUNGEON" << std::endl
    << "Please start by entering one of the following command to choose your hero:"
    << "(s): Shade, (d): Drow, (v): Vampire, (g):Goblin, (t):Troll" << std::endl;

    // ---------------  COMMAND --------------------------- //
    while (std::cin >> command) {
        s.clearAction();
        //  s, d, v, g, t:
        if (command == "s" || command == "d" ||command == "v" 
        || command == "g" || command == "t") {
            // set races
            if (command == "s") pc = new Shade{s.picture(), 's', 4, 6, 125, 25, 15};
            else if (command == "d") pc = new Drow{s.picture(), 's', 4, 6, 150, 25, 15};
            else if (command == "v") pc = new Vampire{s.picture(), 's', 4, 6, 50, 25, 5};
            else if (command == "t") pc = new Troll{s.picture(), 's', 4, 6, 120, 25, 15};
            else if (command == "g") pc = new Goblin{s.picture(), 's', 4, 6, 110, 25, 15};

            s.picture() = pc;
            // start game, spawn enemies, spawn potions  
            curr_g.play();

        } else if (command == "a") {   // attack
            std::cout << "Please specify direction" << std::endl;

            std::string dir;
            std::cin >> dir;
            // attack enemies
            bool atk = pc->attack(dir);

            if (!atk) {
                s.setAction(pc->getAnnouncement());
                pc->move(dir, s.picture());
            } 

        } else if (command == "no" || command == "so" || command == "ea" 
                || command == "we" || command == "ne" || command == "nw" 
                || command == "se" || command =="sw") {

            pc->move(command, s.picture());

        } else if (command == "u" ) {   // use potion
            std::string dir;
            std::cin >> dir;
            // use potion

        } else if (command == "lu") {   // for testing purposes, not actual command
            curr_g.levelUp(pc);
            floor->shuffleStaireCase();
            s.setAction("Next Floor Unlocked! Good job! ");
        } else if (command == "f" ) {   // use potion
            
        }  else if (command == "r" ) {   // use potion
            curr_g.restart(pc);
        }

        if (pc->isDead() || command == "q") {
            std::cout << "womp womp" << std::endl;
            // curr_g.end();
            break;
        } else if (pc->isLevelUp()) {
            curr_g.levelUp(pc);
            floor->shuffleStaireCase();
            s.setAction("Next Floor Unlocked! Good job! ");
        }

        s.setAction(pc->getAnnouncement());
        s.render(pc);
    }
}

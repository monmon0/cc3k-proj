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
#include "PRNG.h"
#include <string>


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
              << "WELCOME to SYLVIA, EASON & MONICA CC3k" << std::endl
    << "Please start by entering one of the following command to choose your hero:"
    << "(s): Shade, (d): Drow, (v): Vampire, (g):Goblin, (t):Troll" << std::endl;

    // ---------------  COMMAND --------------------------- //
    while (std::cin >> command) {
        s.clearAction();
        //  s, d, v, g, t:
        if (command == "s" || command == "d" ||command == "v" 
         || command == "g" || command == "t") {
            // set races
            uint32_t seed = getpid(); 
            PRNG prng(seed); 
            int r1; 
            int r2; 
            while (true) {
                r1 = rand() % 79;
                r2 = rand() % 25;
                if (s.picture()->charAt(r2, r1, 1) == '.') break;
            }

            if (command == "s") pc = new Shade{s.picture(), 's', r1, r2, 125, 25, 15};
            else if (command == "d") pc = new Drow{s.picture(), 's', r1, r2, 150, 25, 15};
            else if (command == "v") pc = new Vampire{s.picture(), 's', r1, r2, 50, 25, 5};
            else if (command == "t") pc = new Troll{s.picture(), 's', r1, r2, 120, 25, 15};
            else if (command == "g") pc = new Goblin{s.picture(), 's', r1, r2, 110, 25, 15};

            s.picture() = pc;
            // start game, spawn enemies, spawn potions  
            curr_g.play();

        } else if (command == "a") {   // attack
            std::cout << "Please specify direction" << std::endl;
            std::string dir;
            std::cin >> dir;
            // attack enemies
            bool hit = 0;       // eason will write attack enemy function in gameplay here
            if (hit) pc->attack(hit);
            else pc->move(dir, s.picture());

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
            // shuffe staircase
            s.setAction("Next Floor Unlocked! Good job! ");
        } else if (command == "f" ) {   // use potion
            
        }  else if (command == "r" ) {   // use potion
            curr_g.restart(pc);
        }

        if (pc->isDead() || command == "q") {
            std::cout << "Womp Womp" << std::endl;
            break;
        } else if (pc->isLevelUp()) {
            curr_g.levelUp(pc);
            s.setAction("Next Floor Unlocked! Good job! ");
        }
        s.setAction(pc->getAnnouncement());
        s.render(pc);
    }
}

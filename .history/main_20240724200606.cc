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
#include "checkCoord.h"
#include <string>

int main() {
    // creating new Dungeon
    Blank * floor = new Blank("map.txt");
    Dungeon s{floor};
    std::string command;
    Player * pc;
    PlayGame curr_g{&s};
    bool initialized = 0;

    // ---------------  COMMAND --------------------------- //
    while (std::cin >> command) {
        s.clearAction();
        //  s, d, v, g, t:
        if (!initialized) {
            
        } else if (initialized) {
            if (command == "a") {   // attack
                std::cout << "Please specify direction: ";
                std::string dir;
                std::cin >> dir;
                // attack enemies
                bool hit = pc->attack(s.picture(), dir);     
                if (hit) curr_g.defeatEnemies(pc->getX(), pc->getY(), dir);
                s.setAction(pc->getAnnouncement());

            } else if (command == "no" || command == "so" || command == "ea" 
                    || command == "we" || command == "ne" || command == "nw" 
                    || command == "se" || command =="sw") {

                pc->move(command, s.picture());
                s.setAction(pc->getAnnouncement());
                curr_g.attackOrMove();

            } else if (command == "u" ) {   // use potion
                std::cout << "Please specify direction: ";
                std::string dir;
                std::cin >> dir;
                pc->takePotion(s.picture(), dir);
                s.setAction(pc->getAnnouncement());
            } else if (command == "lu") {   // Level up, for testing purposes, not actual command
                curr_g.levelUp();
            } else if (command == "f" ) {   // stop enemies from moving;
                curr_g.fPressed(); 
                s.setAction("Something happened to the enemies... "); 
            // --------------- RESTART GAME ------------------------- //
            } else if (command == "r" ) {   // restart game
                curr_g.restart();
                initialized = 0;
            }
            // --------------- QUIT GAME ------------------------- //
            
            
            if (pc->isLevelUp() && s.getLevel() < 5) {
                curr_g.levelUp();
            }

             // --------------- END GAME ------------------------- //
            if (s.getLevel() == 5) {
                curr_g.end();
                std::cin >> command;
                if (command == "r" ) curr_g.restart();
                else break;
            }
            if (command == "a" || command == "u") {
                curr_g.attackOrMove(); 
            }

            if (pc->isDead() || command == "q") {
                curr_g.deadOrQuit();
                std::cin >> command;
                if (command == "r" ) {          // restart game
                    curr_g.restart();  
                    initialized = 0;
                } else break;
            } 

            if (command != "r" && command != "q") {
                s.render(pc);
                std::cout << "Your command: ";
            }
            
        }
    }
}

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
            if (command == "s" || command == "d" ||command == "v" 
                || command == "g" || command == "t") {
                // set races
                curr_g.spawnPlayer(pc, command);
                // --------- start game, spawn enemies, spawn potions -----------  //
                curr_g.play();
                initialized = 1;
                s.setAction(pc->getAnnouncement());
                s.render(pc);
            }   else std::cout << "Please choose an appropriate command: ";
        } else if (initialized) {
            if (command == "a") {   // attack
                std::cout << "Please specify direction: ";
                std::string dir;
                std::cin >> dir;
                // attack enemies
                bool hit = pc->attack(s.picture(), dir);     
                if (hit) curr_g.defeatEnemies(pc->getX(), pc->getY(), dir);
                
            } else if (command == "no" || command == "so" || command == "ea" 
                    || command == "we" || command == "ne" || command == "nw" 
                    || command == "se" || command =="sw") {

                pc->move(command, s.picture());
                curr_g.attackOrMove(); 

            } else if (command == "u" ) {   // use potion
                std::cout << "Please specify direction: ";
                std::string dir;
                std::cin >> dir;
                pc->takePotion(s.picture(), dir);

            } else if (command == "lu") {   // Level up, for testing purposes, not actual command
                curr_g.levelUp();
            } else if (command == "f" ) {   // stop enemies from moving;
                
            // --------------- RESTART GAME ------------------------- //
            } else if (command == "r" ) {   // restart game
                curr_g.restart(pc);
                initialized = 0;
            }

            // --------------- QUIT GAME ------------------------- //
            if (pc->isDead() || command == "q") {
                curr_g.deadOrQuit();
                if (command == "r" ) {          // restart game
                    curr_g.restart(pc);  
                    initialized = 0;
                } else break;
            } 
            
            if (pc->isLevelUp() && s.getLevel() < 5) {
                curr_g.levelUp();
            }

             // --------------- END GAME ------------------------- //
            if (s.getLevel() == 5) {
                curr_g.end();
                std::cin >> command;
                if (command == "r" ) curr_g.restart(pc);
                else break;
            }
            s.setAction(pc->getAnnouncement());
            s.render(pc);
            std::cout << "Your command: ";
        }
    }
}

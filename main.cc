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
    Blank *floor = new Blank("map.txt");
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

                uint32_t seed = getpid();
                CheckCoord c{&s, seed}; 
                c.setPos(); 
                int r1 = c.getX(), r2 = c.getY();

                if      (command == "s") pc = new Shade{s.picture(), 's', r1, r2, 125, 25, 15};
                else if (command == "d") pc = new Drow{s.picture(), 'd', r1, r2, 150, 25, 15};
                else if (command == "v") pc = new Vampire{s.picture(), 'v', r1, r2, 50, 25, 5};
                else if (command == "t") pc = new Troll{s.picture(), 't', r1, r2, 120, 25, 15};
                else if (command == "g") pc = new Goblin{s.picture(), 'g', r1, r2, 110, 25, 15};

                s.picture() = pc;
                curr_g.attachPC(pc); 
                // --------- start game, spawn enemies, spawn potions -----------  //
                curr_g.play();
                initialized = 1;
                s.setAction(pc->getAnnouncement());
                s.render(pc);
            } else std::cout << "Please choose an appropriate command" << std::endl;
        } else if (initialized) {

            if (command == "a") {   // attack
                std::cout << "Please specify direction: ";
                std::string dir;
                std::cin >> dir;
                // attack enemies
                bool hit = pc->attack(s.picture(), dir);     
                if (hit) curr_g.defeatEnemies(pc->getX(), pc->getY(), pc, dir);
                
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
                s.clearAction();
                s.setAction("Next Floor Unlocked! Good job! ");
            } else if (command == "f" ) {   // stop enemies from moving;
                
            // --------------- RESTART GAME ------------------------- //
            } else if (command == "r" ) {   // restart game
                curr_g.restart();
                initialized = 0;
            }

            // --------------- QUIT GAME ------------------------- //
            if (pc->isDead() || command == "q") {
                pc->setAtk(0);
                s.render(pc);
                std::cout << "                 WOMP WOMP !    "           << std::endl;
                std::cout << "             WOULD YOU LIKE TO PLAY AGAIN?" << std::endl;
                std::cout << "   (enter -r to restart)" << std::endl;

                if (command == "r" ) {          // restart game
                    curr_g.restart();  
                    initialized = 0;
                } else break;
            } 
            
            if (pc->isLevelUp() && s.getLevel() < 5) {
                curr_g.levelUp();
                s.setAction("Next Floor Unlocked! Good job! ");
            }

             // --------------- END GAME ------------------------- //
            if (s.getLevel() == 5) {
                curr_g.end();
                std::cin >> command;
                if (command == "r" ) curr_g.restart();
                else break;
            }
            s.setAction(pc->getAnnouncement());
            s.render(pc);
            std::cout << "Your command: ";
        }
    }
}

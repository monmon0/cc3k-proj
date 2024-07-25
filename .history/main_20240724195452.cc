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
                uint32_t seed = getpid();
                CheckCoord c{&s, seed}; 
                c.setPos(); 
                int r1 = c.getX(), r2 = c.getY();
                int location = c.getChamber(); 

                if      (command == "s") pc = new Shade{s.picture(), 's', r1, r2, 125, 25, 25, location};
                else if (command == "d") pc = new Drow{s.picture(), 'd', r1, r2, 150, 25, 15, location};
                else if (command == "v") pc = new Vampire{s.picture(), 'v', r1, r2, 50, 25, 25, location};
                else if (command == "t") pc = new Troll{s.picture(), 't', r1, r2, 120, 25, 15, location};
                else if (command == "g") pc = new Goblin{s.picture(), 'g', r1, r2, 110, 15, 20, location};

                s.picture() = pc;
                curr_g.attachPC(pc); 

                // --------- start game, spawn enemies, spawn potions -----------  //
                curr_g.play();
                initialized = 1;
                s.setAction(pc->getAnnouncement());
                s.render(pc);
                std::cout << "Your command: ";
            }   else std::cout << "Please choose an appropriate command: ";
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
                for (auto it : curr_g->fPressed())
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

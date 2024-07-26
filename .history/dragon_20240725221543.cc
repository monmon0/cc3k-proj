#include "dragon.h"

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord, Dragon_Hoard *dh)
    : Enemy(next, 'D', xCoord, yCoord, 150, 20, 20), dh{dh} {}

void Dragon::atkOrMv(Player *pc, Dungeon *d) {
    announcement = "";
    if (isDead()) {
        dh->unGuarded(); 
        return; 
    }; 

    int xDiff1 = abs(pc->getX() - x); 
    int yDiff1 = abs(pc->getY() - y);  
    int xDiff2 = abs(pc->getX() - dh->getX()); 
    int yDiff2 = abs(pc->getY() - dh->getY());  

    if ((xDiff1 <= 1 && yDiff1 <= 1) || (xDiff2 <= 1 && yDiff2 <= 1)) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        }
    }
}

void Dragon::unguarded(Player *pc, Dungeon *d)

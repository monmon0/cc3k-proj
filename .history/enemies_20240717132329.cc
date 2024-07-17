#include "enemies.h"
#include "Players.h" 

/*
    Assume Player has a loseHP() method, getID() method
*/

void Human::attack(Player& pc) {
    pc.loseHP(Human::getAtk());
}

/

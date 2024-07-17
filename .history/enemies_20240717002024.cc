#include "enemies.h"
#include "Players.h" 

/*
    Assume Player has a loseHP() method, getID() method
*/

void Human::attack(Player& pc) {
    pc.loseHP(Human::getAtk());
}

void Dwarf::attack(Player& pc) {
    pc.loseHP(Dwarf::getAtk());
}

void Elf::attack(Player& pc) {
    if (pc.getID == "drow") {}
    // Implementation of attack logic, e.g. two attacks except for drow
}

void Orc::attack(Player& pc) {
    // Implementation of attack logic, e.g. 50% more damage to goblins
}

void Merchant::attack(Player& pc) {
    // Implementation of attack logic
}

void Dragon::attack(Player& pc) {
    // Implementation of attack logic
}

void Halfling::attack(Player& pc) {
    // Implementation of attack logic, e.g. 50% chance to cause miss
}

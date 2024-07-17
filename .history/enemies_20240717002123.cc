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
    if (pc.getID() == "drow") pc.loseHP(Elf::getAtk());
    else {
        pc.loseHP(Elf::getAtk());
        pc.loseHP(Elf::getAtk());
    }
}

void Orc::attack(Player& pc) {
    if (pc.getID() == "Goblin") pc.loseHP(Orc::getAtk() * 1.5);
    else { pc.loseHP(Prc::getAtk()); }
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

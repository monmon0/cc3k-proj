#include "enemies.h"
#include "Players.h" 

/*
    Assume Player has a loseHP() method, getID() method
*/

void Human::attack(Player& pc) {
    pc.loseHP(Human::getAtk());
}

void Dwarf::attack(Player& pc) {
    // Vampires are allergic to dwarves and lose 5 HP rather than gain
    pc.loseHP(Dwarf::getAtk());
}

void Elf::attack(Player& pc) {
    if (pc.getID() == "drow") { pc.loseHP(Elf::getAtk()); }
    else {
        pc.loseHP(Elf::getAtk());
        pc.loseHP(Elf::getAtk());
    }
}

void Orc::attack(Player& pc) {
    // does 50% more damage to goblins
    if (pc.getID() == "Goblin") { pc.loseHP(Orc::getAtk() * 1.5); }
    else { pc.loseHP(Prc::getAtk()); }
}

void Merchant::attack(Player& pc) {
    pc.loseHP(Merchant::getAtk()); 
}

void Dragon::attack(Player& pc) {
    pc.loseHP(Dragon::getAtk());  
}

void Halfling::attack(Player& pc) {
    // has a 50% chance to cause the player character to miss in combat
    pc.loseHP(Elf::getAtk()); 
}

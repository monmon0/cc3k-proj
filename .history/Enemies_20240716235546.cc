#include "Enemy.h"
#include "PlayerCharacter.h"

void Human::attack(PlayerCharacter& pc) {
    // Implementation of attack logic
}

void Dwarf::attack(PlayerCharacter& pc) {
    // Implementation of attack logic, e.g. affecting Vampires
}

void Elf::attack(PlayerCharacter& pc) {
    // Implementation of attack logic, e.g. two attacks except for drow
}

void Orc::attack(PlayerCharacter& pc) {
    // Implementation of attack logic, e.g. 50% more damage to goblins
}

void Merchant::attack(PlayerCharacter& pc) {
    // Implementation of attack logic
}

void Dragon::attack(PlayerCharacter& pc) {
    // Implementation of attack logic
}

void Halfling::attack(PlayerCharacter& pc) {
    // Implementation of attack logic, e.g. 50% chance to cause miss
}

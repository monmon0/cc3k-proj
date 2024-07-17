#include "EnemyFactory.h"
#include <stdexcept>

Enemy* EnemyFactory::createEnemy(const std::string& type) {
    if (type == "human") {
        return new Human();
    } else if (type == "dwarf") {
        return new Dwarf();
    } else if (type == "elf") {
        return new Elf();
    } else if (type == "orc") {
        return new Orc();
    } else if (type == "merchant") {
        return new Merchant();
    } else if (type == "dragon") {
        return new Dragon();
    } else if (type == "halfling") {
        return new Halfling();
    } else {
        throw std::invalid_argument("Unknown enemy type: " + type);
    }
}
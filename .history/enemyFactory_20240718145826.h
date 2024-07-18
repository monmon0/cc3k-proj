#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemies.h"

class EnemyFactory : public Dungeon {
    public:
        std::unique_ptr<Enemy> createEnemy(const std::string& type, AsciiArt* next, int x, int y) {
            if (type == "Human") {
                return std::make_unique<Human>(next, x, y);
            } else if (type == "Dwarf") {
                return std::make_unique<Dwarf>(next, x, y);
            } else if (type == "Elf") {
                return std::make_unique<Elf>(next, x, y);
            } else if (type == "Orc") {
                return std::make_unique<Orc>(next, x, y);
            } else if (type == "Merchant") {
                return std::make_unique<Merchant>(next, x, y);
            } else if (type == "Dragon") {
                return std::make_unique<Dragon>(next, x, y);
            } else if (type == "Halfling") {
                return std::make_unique<Halfling>(next, x, y);
            } else {
                return nullptr;
            }
        }
};

#endif 

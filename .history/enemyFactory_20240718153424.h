#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemies.h"
#include "dungeon.h"

class EnemyFactory {
        std::unique_ptr<Enemy> createEnemy(const std::string& type, AsciiArt* next, int x, int y) {
            switch (type) {
                case "Human": return std::make_unique<Human>(next, x, y); break;
                case "Dwarf": return std::make_unique<Dwarf>(next, x, y); break;
                case "Elf": return std::make_unique<Elf>(next, x, y); break;
                case "Orc": return std::make_unique<Orc>(next, x, y); break;
                case "Merchant": return std::make_unique<Merchant>(next, x, y); break;
                case "Dragon": return std::make_unique<Dragon>(next, x, y); break;
                case "Halfling": return std::make_unique<Halfling>(next, x, y); break;
                default: return nullptr; break;
            }
        }

        public:
};

#endif 



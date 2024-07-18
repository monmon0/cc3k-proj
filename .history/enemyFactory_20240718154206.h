#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <vector>

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
        std::vector<Enemy *> spawn20Enemies(AsciiArt* next) {
            std::vector<char> characters = ['H', 'H', 'H', 'H', 'W', 'W', 'W', 'L', 'L', 'L', 'L', 'L', 'E', 'E', 'O', 'O', 'M', 'M']
            std::vector<Enemy *> e(20);
            for (int i = 0; i < 20; i++) {
                int x, y;

                if (next->charAt(x, y) == '.') e.emplace_back(createEnemy("Human", next, x, y)); 
                else { i-- }; 
            }
        }
};

#endif 



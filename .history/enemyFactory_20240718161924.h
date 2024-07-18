#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <vector>
#include <algorithm>
#include <random>

#include "Enemies.h"
#include "dungeon.h"

class EnemyFactory {
        std::unique_ptr<Enemy> createEnemy(const char type, AsciiArt* next, int x, int y) {
            switch (type) {
                case 'H': return std::make_unique<Human>(next, x, y); break;
                case 'W': return std::make_unique<Dwarf>(next, x, y); break;
                case 'E': return std::make_unique<Elf>(next, x, y); break;
                case 'O': return std::make_unique<Orc>(next, x, y); break;
                case 'M': return std::make_unique<Merchant>(next, x, y); break;
                case 'D': return std::make_unique<Dragon>(next, x, y); break;
                case 'L': return std::make_unique<Halfling>(next, x, y); break;
                default: return nullptr; break;
            }
        }
    public:
        std::vector<Enemy *> spawn20Enemies(AsciiArt *next, int tick) {
            std::vector<char> characters = ['H', 'H', 'H', 'H', 'W', 'W', 'W', 'L', 'L', 'L', 'L', 'L', 'E', 'E', 'O', 'O', 'M', 'M'];
            std::vector<Enemy *> e(20);

            std::default_random_engine engine;
            std::shuffle(characters.begin(), characters.end(), engine);

            for (int i = 0; i < 20; i++) {
                int x, y;

                if (next->charAt(x, y, tick) == '.') e.emplace_back(createEnemy(characters[0], next, x, y)); 
                else { i--; }; 
            }

            return e;
        }
};

#endif 



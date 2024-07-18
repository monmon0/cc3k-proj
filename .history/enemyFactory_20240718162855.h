#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "Enemies.h"

class EnemyFactory {
    std::unique_ptr<Enemy> createEnemy(const char type, AsciiArt* next, int x, int y);
public:
    std::vector<std::unique_ptr<Enemy>> spawn20Enemies(AsciiArt *next, int tick);
};

std::unique_ptr<Enemy> EnemyFactory::createEnemy(const char type, AsciiArt* next, int x, int y) {
    switch (type) {
        case 'H': return std::make_unique<Human>(next, x, y);
        case 'W': return std::make_unique<Dwarf>(next, x, y);
        case 'E': return std::make_unique<Elf>(next, x, y);
        case 'O': return std::make_unique<Orc>(next, x, y);
        case 'M': return std::make_unique<Merchant>(next, x, y);
        case 'D': return std::make_unique<Dragon>(next, x, y);
        case 'L': return std::make_unique<Halfling>(next, x, y);
        default: return nullptr;
    }
}

std::vector<std::unique_ptr<Enemy>> EnemyFactory::spawn20Enemies(AsciiArt *next, int tick) {
    std::vector<char> characters = {'H', 'H', 'H', 'H', 'W', 'W', 'W', 'L', 'L', 'L', 'L', 'L', 'E', 'E', 'O', 'O', 'M', 'M'};
    std::vector<std::unique_ptr<Enemy>> e;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(characters.begin(), characters.end(), g);

    for (int i = 0; i < 20; i++) {
        int x = rand() % 79;
        int y = rand() % 25;

        if (next->charAt(x, y, tick) == '.') {
            e.emplace_back(createEnemy(characters[i], next, x, y));
        } else {
            i--; // Retry the placement
        }
    }

    return e;
}

#endif

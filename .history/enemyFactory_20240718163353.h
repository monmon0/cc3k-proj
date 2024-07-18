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

#endif // ENEMYFACTORY_H

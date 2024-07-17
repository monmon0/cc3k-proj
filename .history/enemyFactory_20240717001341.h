#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemies.h"

class EnemyFactory {
public:
    static Enemy* createEnemy(const std::string& type);
};

#endif 
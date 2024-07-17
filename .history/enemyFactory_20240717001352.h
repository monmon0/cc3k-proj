#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemies.h"

class EnemyFactory {
public:
    static enemyy* createEnemy(const std::string& type);
};

#endif 
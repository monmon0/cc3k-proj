#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"

class EnemyFactory {
public:
    static Enemy* createEnemy(const std::string& type);
};

#endif 
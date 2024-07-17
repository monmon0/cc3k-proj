#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemies.h"

class EnemyFactory {
public:
    static enemy* createEnemy(const std::string& type);
};

#endif 
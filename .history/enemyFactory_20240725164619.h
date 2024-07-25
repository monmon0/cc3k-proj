#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <memory>
<<<<<<< Updated upstream

#include "Enemies.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h" 

class EnemyFactory {
    public:
        enum Type {HUMAN, DWARF, ELF, ORC, MERCHANT, HALFLING};
        static Enemy *createEnemy(Type type, AsciiArt *next, int x, int y);
};



#include "enemyFactory.h"
// using namespace ItemFactory;

Enemy *EnemyFactory::createEnemy(Type type, AsciiArt *next, int x, int y) {
    // Create Potions
    if (type == Type::HUMAN) {
        return new RH(next, x, y, "RH");
    } else if (type == Type::DWARF) {
        return new BA(next, x, y, "BA");
    } else if (type == Type::ELF) {
        return new BD(next, x, y, "BD");
    } else if (type == Type::ORC) {
        return new PH(next, x, y, "PH");
    } else if (type == Type::MERCHANT) {
        return new WA(next, x, y, "WA");
    } else if (type == Type::HALFLING) {
        return new WD(next, x, y, "WD");
    } else if {type == Type::HALFLING

    }
}



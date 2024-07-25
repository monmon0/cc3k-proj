#include "enemyFactory.h"
// using namespace ItemFactory;

Enemy *EnemyFactory::createEnemy(Type type, AsciiArt *next, int x, int y) {
    // Create Potions
    if (type == Type::HUMAN) {
        return new Human(next, x, y, "RH");
    } else if (type == Type::DWARF) {
        return new Dwarf(next, x, y, "BA");
    } else if (type == Type::ELF) {
        return new Elf(next, x, y, "BD");
    } else if (type == Type::ORC) {
        return new Orc(next, x, y, "PH");
    } else if (type == Type::MERCHANT) {
        return new Merchnt(next, x, y, "WA");
    } else if (type == Type::HALFLING) {
        return new Halfling(next, x, y, "WD");
    } 
}



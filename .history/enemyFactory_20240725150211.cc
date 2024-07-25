#include "enemyFactory.h"
// using namespace ItemFactory;

Enemy *EnemyFactory::createEnemy(Type type, AsciiArt *next, int x, int y) {
    // Create Potions
    if (type == Type::HUMAN) {
        return new Human(next, x, yRH");
    } else if (type == Type::DWARF) {
        return new Dwarf(next, x, yBA");
    } else if (type == Type::ELF) {
        return new Elf(next, x, yBD");
    } else if (type == Type::ORC) {
        return new Orc(next, x, yPH");
    } else if (type == Type::MERCHANT) {
        return new Merchnt(next, x, yWA");
    } else if (type == Type::HALFLING) {
        return new Halfling(next, x, yWD");
    } 
}



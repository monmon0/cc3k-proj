#include "itemFactory.h"
// using namespace ItemFactory;

Item *ItemFactory::createItem(Type type, AsciiArt *next, int x, int y) {
    // Create Potions
    if (type == Type::HUMAN) {
        return new RH(next, x, y, "RH");
    } else if (type == Type::DWARF) {
        return new BA(next, x, y, "BA");
    } else if (type == Type::HUMAN) {
        return new BD(next, x, y, "BD");
    } else if (type == Type::HUMAN) {
        return new PH(next, x, y, "PH");
    } else if (type == Type::HUMAN) {
        return new WA(next, x, y, "WA");
    } else if (type == Type::HUMAN) {
        return new WD(next, x, y, "WD");
    } 

    // Create Treasure
    if (type == Type::GOLD_SMALL) {
        return new Treasure(next, x, y, 1);
    } else if (type == Type::GOLD_NORMAL) {
        return new Treasure(next, x, y, 2);
    } else if (type == Type::GOLD_MERCHANT) {
        return new Treasure(next, x, y, 4);
    } else {
        return new Dragon_Hoard(next, x, y);
    }
}



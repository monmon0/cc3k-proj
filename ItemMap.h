#ifndef POTIONMAP_H
#define POTIONMAP_H

#include "Potion.h"
#include "Treasure.h"
#include <map>
#include <utility>
using namespace std;

map<pair<int, int>, Potion *potion> pMap;
map<pair<int, int>, Potion *potion> gMap;

void addPotion(int x, int y, Potion* potion) {
    pMap[make_pair(x, y)] = potion;
}

void addGold(int x, int y, Treasure *treasure) {
    gMap[make_pair(x, y)] = treasure;
}

Potion *getPotion(int x, int y) {
    for (auto &p : pMap) {
        if (p.first == make_pair(x, y)) {
            return p.second;
        }
    }
    return nullptr;
}

Potion *getGold(int x, int y) {
    for (auto &p : gMap) {
        if (p.first == make_pair(x, y)) {
            return p.second;
        }
    }
    return nullptr;
}

void deletePotion() {
    for (auto &p : pMap) {
        delete p.second;
    } 
}

void deleteGold() {
    for (auto &p : gMap) {
        delete p.second;
    } 
}

#endif

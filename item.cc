#include "item.h"

Item::Item(AsciiArt *next, int x, int y, int amt) : Decorator{next},
                                                    x{x},
                                                    y{y},
                                                    amt{amt}{}

int Item::getAmt() {
    return amt;
}

void Item::addItem(int x, int y, Item* item) {
    iMap[make_pair(x, y)] = item;
}

Item *Item::getItem(int x, int y) {
    for (auto &item : iMap) {
        if (item.first == make_pair(x, y)) {
            return item.second;
        }
    }
    return nullptr;
}

void Item::deleteItem(Item *item) {
    for (auto it = iMap.begin(); it != iMap.end(); ++it) {
        if (it->second == item) {
            iMap.erase(it);
            break;
        }
    }
}

void Item::deleteAll() {
    for (auto &item : iMap) {
        delete item.second;
    }
}

int Item::getX() {
    return x;
}

int Item::getY() {
    return y;
}

AsciiArt *&Item::nextChar() {
    return next;
}

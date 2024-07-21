#include "item.h"

Item::Item(AsciiArt *next, int x, int y, int amt) : Decorator{next},
                                                    x{x},
                                                    y{y},
                                                    amt{amt}{}

int Item::getAmt() {
    return amt;
}

void Item::addItem(int x, int y, Item* item) {
    iVec.emplace_back(item);
}

Item *Item::getItem(int x, int y) {
    for (auto &item : iVec) {
        if (item->getX() == x && item->getY() == y) {
            return item;
        }
    }
    return nullptr;
}

void Item::deleteItem(Item *item) {
    auto it = iVec.begin();
    while (it != iVec.end()) {
        if (*it == item) {
            iVec.erase(it);
            break;
        }
        ++it;
    }
}

void Item::deleteAll() {
    for (auto &item : iVec) {
        delete item;
    }
    iVec.clear();
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

#include "item.h"

Item::Item(AsciiArt *next, int x, int y, double amt) : Decorator{next},
                                                    x{x},
                                                    y{y},
                                                    amt{amt}{
    addItem(this);
}

double Item::getAmt() {
    return amt;
}

bool Item::collectable() {
    return true;
}

string Item::getAnnouncement() const {
    return announcement;
}

void Item::addItem(Item* item) {
    iVec.emplace_back(item);
}

Item *Item::getItem(int x, int y) {
    for (auto item : iVec) {
        if (item->getX() == x && item->getY() == y) {
            return item;
        }
    }
    return nullptr;
}

void Item::deleteAll() {
    for (Item *item : iVec) {
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

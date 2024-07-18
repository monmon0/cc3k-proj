#include "Treasure.h" 


void Treasure::deleteTreasure(Treasure *tr) {
    for (auto it = gMap.begin(); it != gMap.end(); ++it) {
        if (it->second == tr) {
            gMap.erase(it);
            break;
        }
    }
}

char Treasure::charAt(int x, int y, int tick) {
    if (x == this->x && y == this->y) {
        return 'G';
    }
    return next->charAt(x, y, tick);
}

int Treasure::getVal() const {
    return val;
}

Treasure::Treasure(AsciiArt *art, int x, int y, int val): Decorator{art}, x{x}, y{y}, val{val}{
    addTreasure(x, y, this);
}

void Treasure::addTreasure(int x, int y, Treasure *tr) {
    gMap[make_pair(x, y)] = tr;
}

void Treasure::deleteAllT() {
    for (auto &tr : gMap) {
        delete tr.second;
    }
}


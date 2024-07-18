#include "Treasure.h" 

void Treasure::deleteTreasure(Treasure *tr) {

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

Treasure::Treasure(int x, int y, int val): x{x}, y{y}, val{val}{
    addTreasure(this);
}

void Treasure::addTreasure(Treasure *tr) {
    gMap[make_pair(x, y)] = tr;
}

void Treasure::deleteAllT() {
    for (auto &tr : gMap) {
        delete tr.second;
    }
}


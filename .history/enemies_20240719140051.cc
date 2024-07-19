#include "Enemies.h"

char Enemy::charAt(int row, int col, int tick) {
    if (col == x && row == y) {
        switch(getRace()) {
            case 'H': return 'H'; 
            case 'W': return 'W'; 
            case 'E': return 'E'; 
            case 'O': return 'O';
            case 'M': return 'M';
            case 'D': return 'D'; 
            case 'L': return 'L'; 
            }
    } else {
        return charAt(row, col, tick); 
    }
}

void Enemy::addEnemy(int x, int y, Enemy* e) {
    pMap[make_pair(x, y)] = e;
}

Enemy *Enemy::getEnemy(int x, int y) {
    for (auto &p : pMap) {
        if (p.first == make_pair(x, y)) {
            return p.second;
        }
    }
    return nullptr;
}

void Enemy::deleteAll() {
    for (auto &p : pMap) {
        delete p.second;
    }
}

void Enemy::deleteEnemy(Enemy *Enemy) {
    for (auto it = pMap.begin(); it != pMap.end(); ++it) {
        if (it->second == Enemy) {
            pMap.erase(it);
            break;
        }
    }
}

// Enemy class implementation
Enemy::Enemy(AsciiArt *next, char id, int x, int y, int hp, int atk, int def)
    : Character(next, id, x, y, hp, atk, def) {}

// Human class implementation
Human::Human(AsciiArt *next, int x, int y)
    : Enemy(next, 'H', x, y, 140, 20, 20) {
}

// Dwarf class implementation
Dwarf::Dwarf(AsciiArt *next, int x, int y)
    : Enemy(next, 'W', x, y, 100, 20, 30) {
}

// Elf class implementation
Elf::Elf(AsciiArt *next, int x, int y)
    : Enemy(next, 'E', x, y, 140, 30, 10) {
}

// Orc class implementation
Orc::Orc(AsciiArt *next, int x, int y)
    : Enemy(next, 'O', x, y, 180, 30, 25) {
}

// Merchant class implementation
Merchant::Merchant(AsciiArt *next, int x, int y)
    : Enemy(next, 'M', x, y, 30, 70, 5) {
}

// Dragon class implementation
Dragon::Dragon(AsciiArt *next, int x, int y)
    : Enemy(next, 'D', x, y, 150, 20, 20) {
}

// Halfling class implementation
Halfling::Halfling(AsciiArt *next, int x, int y)
    : Enemy(next, 'L', x, y, 100, 15, 20) {
}

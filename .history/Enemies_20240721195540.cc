#include "Enemies.h"

#include <iostream>

// Implement the Enemy constructor
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Implement the virtual charAt method
char Enemy::charAt(int row, int col, int tick) {
    if (col == x && row == y) {
        char id = getRace(); 
        if (id == 'H') return 'H'; 
        else if (id == 'W') return 'W'; 
        else if (id == 'E') return 'E'; 
        else if (id == 'O') return 'O';
        else if (id == 'M') return 'M';
        else if (id == 'D') return 'D'; 
        else if (id == 'L') return 'L'; 
    } else {
        return next->charAt(row, col, tick);; 
    }
}

void Enemy::atkOrMv(Player *pc, Dungeon *d) {
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) {
        double damage = ceiling((100/(100 + pc->getDef())) * getAtk()); 
        pc->changeHP(-damage); 
        announcement = std::to_string() + " deals " + getAtk() + " damage to PC."; 
    } else {
        while (! fPressed) {
            int idx = rand() % 3;
            int dx = arr[idx]; 
            idx = rand() % 3;
            int dy = arr[idx]; 

            char pos_check = d->picture()->charAt(y + dy, x + dx, 1);

            if (pos_check == '.') {
                x += dx;
                y += dy;
                break; 
            } 
        } 
    }
}

// Implement constructors for derived classes
Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {}

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'D', xCoord, yCoord, 100, 20, 30) {}

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {}

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {}

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {}

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'R', xCoord, yCoord, 150, 20, 20) {}

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {}

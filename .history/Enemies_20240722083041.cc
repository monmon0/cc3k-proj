#include "Enemies.h"

#include <iostream>

// Implement the Enemy constructor
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Implement the virtual charAt method
char Enemy::charAt(int row, int col, int tick) {
    if (col == x && row == y && !isDead()) {
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

// --------------------- Human --------------------- //
Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {}

void Human::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        }
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

// --------------------- Dwarf --------------------- //

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'W', xCoord, yCoord, 100, 20, 30) {}

// --------------------- Elf --------------------- //

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {}

void Elf::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        } 
        
        if (pc->getRace() != 'd') {
            if (rand() % 2 == 0) {
                pc->changeHP(-damage); 
                announcement += "On the second try "
                                + std::string(1, getRace())  // Convert char to std::string
                                + " deals " 
                                + std::to_string(damage)  // Convert int to std::string
                                + " damage to PC. ";
            } else {
                announcement += "On the second try " + std::string(1, getRace()) + " missed. "; 
            }
        }
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

// --------------------- Orc --------------------- //

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {}

void Orc::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) { 
        int atk = getAtk()
        if (pc->getRace() == 'g') 
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        }
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

// --------------------- Merchant --------------------- //

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {}

// --------------------- Dragon --------------------- //

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'D', xCoord, yCoord, 150, 20, 20) {}

// --------------------- Halfling --------------------- //

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {}

#include "Enemies.h"

#include <iostream>

// Implement the Enemy constructor
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Implement the virtual charAt method
char Enemy::charAt(int row, int col) {
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
        return next->charAt(row, col);; 
    }
}

bool Enemy::isDead() const { return hp <= 0; } 

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
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
    }
}

// --------------------- Dwarf --------------------- //

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'W', xCoord, yCoord, 100, 20, 30) {} 

void Dwarf::atkOrMv(Player *pc, Dungeon *d) {
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
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
    }
}

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
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
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
        int atk = getAtk(); 
        if (pc->getRace() == 'g') atk *= 1.5; 
        int damage = ceil((100/(100 + pc->getDef())) * atk); 
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
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
    }
}

// --------------------- Merchant --------------------- //

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {}

void Merchant::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1 && !pc->isFriend()) {
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
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
    }
}

// --------------------- Dragon --------------------- //

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord, Dragon_Hoard *dh)
    : Enemy(next, 'D', xCoord, yCoord, 150, 20, 20), dh{dh} {}

void Dragon::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) {
        dh->unGuarded(); 
        return; 
    }; 
    announcement = "";

    int xDiff1 = abs(pc->getX() - x); 
    int yDiff1 = abs(pc->getY() - y);  
    int xDiff2 = abs(pc->getX() - dh->getX()); 
    int yDiff2 = abs(pc->getY() - dh->getY());  

    if ((xDiff1 <= 1 && yDiff1 <= 1) || (xDiff2 <= 1 && yDiff2 <= 1)) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            pc->getHitbyHalfing(); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        }
    }
}

// --------------------- Halfling --------------------- //

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {}

void Halfling::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            pc->getHitbyHalfing(); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        } 
        if (rand() % 2 == 0) {
            pc->getHitbyHalfing(); 
            announcement += "PC is poisoned by Halfling. "; 
        }
    } else { 
        for (int i : arr) {
            for (int j : arr) {
                if d->picture()->charAt(y + i, x + j) == '.';  
                while (! fPressed) {
                    int idx = rand() % 3;
                    int dx = arr[idx]; 
                    idx = rand() % 3;
                    int dy = arr[idx]; 

                    char pos_check = d->picture()->charAt(y + dy, x + dx);

                    if (pos_check == '.') {
                        x += dx;
                        y += dy;
                        break; 
                    } 
                } 
            }
        }
        return; 
    }
}

#ifndef ENEMIES_H
#define ENEMIES_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"
#include "gameplayfunc.h"

#include <string>
#include <vector>

class Enemy : public Character {
public:
    Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);

    ~Enemy() = default; 

    void moveX(int dx) { x += dx; }
    void moveY(int dy) { y += dy; }
    bool isDead() { return hp <= 0; }
    void attack(Player& pc) { pc.changeHP(-getAtk()); }
    char charAt(int row, int col, int tick) override;
};

class Human : public Enemy {
public:
    Human(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {}
};

class Dwarf : public Enemy {
public:
    Dwarf(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'D', xCoord, yCoord, 100, 20, 30) {}
};

class Elf : public Enemy {
public:
    Elf(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {}
};

class Orc : public Enemy {
public:
    Orc(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {}
};

class Merchant : public Enemy {
public:
    Merchant(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'M', xCoord, yCoord, 75, 25, 5) {}
};

class Dragon : public Enemy {
public:
    Dragon(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'R', xCoord, yCoord, 150, 30, 20) {}
};

class Halfling : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord)
        : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {}
};

#endif // ENEMIES_H

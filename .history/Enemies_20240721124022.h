#ifndef ENEMIES_H
#define ENEMIES_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"
#include "PRNG.h"
#include "Dungeon."

#include <string>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <random>

class Enemy : public Character {
public:
    Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);

    ~Enemy() = default; 

    bool fPressed = false; 
    void atkOrMv(Player *pc, Dungeon *curr);
    bool isDead() { return hp <= 0; }
    void attack(Player& pc) { pc.changeHP(-getAtk()); }
    char charAt(int row, int col, int tick) override;
};

class Human : public Enemy {
public:
    Human(AsciiArt *next, int xCoord, int yCoord); 
};

class Dwarf : public Enemy {
public:
    Dwarf(AsciiArt *next, int xCoord, int yCoord);
};

class Elf : public Enemy {
public:
    Elf(AsciiArt *next, int xCoord, int yCoord);
};

class Orc : public Enemy {
public:
    Orc(AsciiArt *next, int xCoord, int yCoord);
};

class Merchant : public Enemy {
public:
    Merchant(AsciiArt *next, int xCoord, int yCoord);
};

class Dragon : public Enemy {
public:
    Dragon(AsciiArt *next, int xCoord, int yCoord);
};

class Halfling : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord);
};

#endif // ENEMIES_H

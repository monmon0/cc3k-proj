#ifndef ENEMIES_H
#define ENEMIES_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"
#include "PRNG.h"
#include "dungeon.h"
#include "checkCoord.h"

#include <cmath>
#include <string>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <random>

class Dungeon; 

class Enemy : public Character {
public:
    Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);

    ~Enemy() = default; 

    bool fPressed = false; 
    bool isDead() { return hp <= 0; }
    void attack(Player& pc) { pc.changeHP(-getAtk()); }
    void loseHP(double damage) { hp -= damage; }
    char charAt(int row, int col, int tick) override;
    virtual void atkOrMv(Player *pc, Dungeon *d) = 0; 
};

class Human : public Enemy {
public:
    Human(AsciiArt *next, int xCoord, int yCoord); 
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Dwarf : public Enemy {
public:
    Dwarf(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Elf : public Enemy {
public:
    Elf(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Orc : public Enemy {
public:
    Orc(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Merchant : public Enemy {
public:
    Merchant(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Dragon : public Enemy {
public:
    Dragon(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

class Halfling : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord);
    void atkOrMv(Player *pc, Dungeon *d) override; 
};

#endif // ENEMIES_H

#ifndef ENEMIES_H
#define ENEMIES_H

#include "Players.h"
#include "decorator.h"
#include "PRNG.h"
#include "dungeon.h"
#include "checkCoord.h"
#include "character.h"

#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <cstdlib> 
#include <algorithm>

class Dungeon; 
// class Dragon_Hoard;

class Enemy : public Character {
public:
    Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);
    ~Enemy() = default; 

    bool fPressed = false; 
    bool goldDropped = false; 
    void attack(Player& pc) { pc.changeHP(-getAtk()); }
    char charAt(int row, int col) override;
    void loseHP(double damage) { hp -= damage; }
    bool isDead() const = 0;
    virtual void atkOrMv(Player *pc, Dungeon *d) = 0; 
};

#endif // ENEMIES_H

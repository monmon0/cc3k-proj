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

    protected:
        static inline map<pair<int, int>, Enemy *> eMap;

    public:
        Enemy(AsciiArt *next, char id, int x, int y, int hp, int atk, int def);
        ~Enemy() = default; 

        void moveX(int dx) { x += dx; }
        void moveY(int dy) { y += dy; }
        bool isDead() { return hp <= 0; }
        void attack(Player& pc) { pc.changeHP( -getAtk() ); };
        static void addEnemy(int x, int y, Enemy* e);
        static Enemy *getEnemy(int x, int y);
        static void deleteEnemy(Enemy *e);
        static void deleteAll();
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

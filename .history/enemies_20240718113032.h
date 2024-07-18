#ifndef ENEMIES_H
#define ENEMIES_H
#include "asciiart.h"
#include "Subject.h"
#include "Players.h"

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Enemy : public Decorator {
        std::vector<char> surroundings;

    protected: 
        char ID; 
        int xCoord;
        int yCoord;
        int hp;
        int atk;
        int def;

    public:
        Enemy(AsciiArt *next, char id, int x, int y, int hp, int atk, int def)
            : Decorator(next), ID{id}, xCoord(x), yCoord(y), hp(hp), atk(atk), def(def) {} 
        virtual ~Enemy() {}

        int getX() const { return xCoord; }
        int getY() const { return yCoord; }
        void moveX(int dx) { xCoord += dx; }
        void moveY(int dy) { yCoord += dy; }
        int getHp() const { return hp; }
        int getAtk() const { return atk; }
        int getDef() const { return def; }
        void loseHP(int damage) { hp -= damage; }
        bool isDead() { return hp <= 0; }
        void attack(Player& pc) { pc.changeHP( -getAtk() ); };
        char getState() { return ID; }
        virtual char charAt(int row, int col, int tick) = 0;
};

// ------------------------------------------------------------------

class Human : public Enemy {
    public:
        Human(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {
    // Attach observer here if necessary 
}

char Human::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Dwarf : public Enemy {
    public:
        Dwarf(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'W', xCoord, yCoord, 100, 20, 30) {
    // Attach observer here if necessary 
}

char Human::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Elf : public Enemy {
    public:
        Elf(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {
    // Attach observer here if necessary 
}

// ------------------------------------------------------------------

class Orc : public Enemy {
    public:
        Orc(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {
    // Attach observer here if necessary 
}

// ------------------------------------------------------------------

class Merchant : public Enemy {
        bool hostile = false;
    public:
        Merchant(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {
    // Attach observer here if necessary 
}

// ------------------------------------------------------------------

class Dragon : public Enemy {
    public:
        Dragon(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'D', xCoord, yCoord, 150, 20, 20) {
    // Attach observer here if necessary 
}

// ------------------------------------------------------------------

class Halfling : public Enemy {
    public:
        Halfling(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
};

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {
    // Attach observer here if necessary 
}

#endif 

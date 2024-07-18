#ifndef ENEMIES_H
#define ENEMIES_H
#include "asciiart.h"
#include "Subject.h"
#include "Players.h"

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Enemy : public Decorator, public Subject {
        std::vector<char> surroundings;

    protected: 
        int xCoord;
        int yCoord;
        int hp;
        int atk;
        int def;

    public:
        Enemy(AsciiArt *next, int x, int y, int hp, int atk, int def)
            : Decorator(next), xCoord(x), yCoord(y), hp(hp), atk(atk), def(def) {} 
        virtual ~Enemy() {}

        int getX() const { return xCoord; }
        int getY() const { return yCoord; }
        void moveX(int dx) { xCoord += dx; notifyObservers(); }
        void moveY(int dy) { yCoord += dy; notifyObservers(); }
        int getHp() const { return hp; }
        int getAtk() const { return atk; }
        int getDef() const { return def; }
        void loseHP(int damage) { hp -= damage; }
        bool isDead() { return hp <= 0; }
        void attack(Player& pc) { pc.changeHP( -getAtk() ) };
        virtual char charAt(int row, int col, int tick) = 0;
};

// ------------------------------------------------------------------

class Human : public Enemy {
    public:
        Human(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 140, 20, 20) {
    // Attach observer here if necessary 
}

char Human::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Dwarf : public Enemy {
    public:
        Dwarf(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 100, 20, 30) {
    // Attach observer here if necessary 
}

char Dwarf::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Elf : public Enemy {
    public:
        Elf(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 140, 30, 10) {
    // Attach observer here if necessary 
}

char Elf::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Orc : public Enemy {
    public:
        Orc(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 180, 30, 25) {
    // Attach observer here if necessary 
}

char Orc::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Orc : public Enemy {
    public:
        Orc(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 180, 30, 25) {
    // Attach observer here if necessary 
}

char Orc::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// class Dragon : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Dragon() { randNum1; randNum2; hp = 150; atk = 20; def = 20; }
//         void attack(Player& pc) override;
// };

// class Halfling : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Halfling() { randNum1; randNum2; hp = 100; atk = 15; def = 20; }
//         void attack(Player& pc) override;
// };

#endif 

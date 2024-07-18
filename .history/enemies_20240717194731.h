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

void Human::attack(Player &pc) {
    pc.ChangeHP(- getAtk()); 
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

void Dwarf::attack(Player &pc) {
    pc.ChangeHP(- getAtk()); 
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

void Elf::attack(Player &pc) {
    if (pl.getRace() != "D") pc.ChangeHP(- getAtk()); 
    pc.ChangeHP(- getAtk()); 
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

void Orc::attack(Player &pc) {
    if (pl.getRace() == "G") pc.ChangeHP(- getAtk() * 1.5); 
    else { pc.ChangeHP(- getAtk()); }
}

// ------------------------------------------------------------------

class Merchant : public Enemy {
        bool hostile = false;
    public:
        Merchant(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 30, 70, 5) {
    // Attach observer here if necessary 
}

char Merchant::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

void Merchant::attack(Player &pc) {
    if (pl.getRace() == "G") pc.ChangeHP(- getAtk() * 1.5); 
    else { pc.ChangeHP(- getAtk()); }
}

// ------------------------------------------------------------------

class Dragon : public Enemy {
    public:
        Dragon(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 150, 20, 20) {
    // Attach observer here if necessary 
}

char Dragon::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

// ------------------------------------------------------------------

class Halfling : public Enemy {
    public:
        Halfling(AsciiArt *next, int xCoord, int yCoord); 
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, xCoord, yCoord, 100, 15, 20) {
    // Attach observer here if necessary 
}

char Halfling::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

#endif 

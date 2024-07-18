#ifndef ENEMIES_H
#define ENEMIES_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "Decorator.h"
#include <string>
#include <vector>

class Enemy : public Decorator {
protected:
    std::vector<char> surroundings;
    char ID; 
    int xCoord;
    int yCoord;
    int hp;
    int atk;
    int def;

public:
    Enemy(AsciiArt *next, char id, int x, int y, int hp, int atk, int def);
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

class Human : public Enemy {
public:
    Human(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Dwarf : public Enemy {
public:
    Dwarf(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Elf : public Enemy {
public:
    Elf(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Orc : public Enemy {
public:
    Orc(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Merchant : public Enemy {
public:
    Merchant(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Dragon : public Enemy {
public:
    Dragon(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

class Halfling : public Enemy {
public:
    Halfling(AsciiArt *next, int xCoord, int yCoord); 
    char charAt(int row, int col, int tick) override;
};

#endif // ENEMIES_H

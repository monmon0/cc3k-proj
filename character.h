#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"
#include "asciiart.h"

class Character : public Decorator {
protected: 
    char race; 
    int x;
    int y;
    int hp;
    int atk;
    int def;

public:
    Character(AsciiArt *next, char id, int x, int y, int hp, int atk, int def);
    ~Character() = default; 

    int getX() const;
    int getY() const;
    int getHp() const;
    int getAtk() const;
    int getDef() const;

    void changeHP(int damage);
    bool isDead();
    char getRace();

    virtual char charAt(int row, int col, int tick) = 0;
};

#endif // CHARACTER_H

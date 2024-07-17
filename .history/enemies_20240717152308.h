#ifndef ENEMIES_H
#define ENEMIES_H
#include "Subject.h"
#include "enemyObserver.h"

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Enemy : public Decorator {
        std::vector<char> surroundings;

    protected: 
        int xCoord;
        int yCoord;
        int hp;
        int atk;
        int def;

    public:
        virtual ~Enemy() {}
        int getX() const { return xCoord; }
        int getY() const { return yCoord; }
        void moveX(int dx) { xCoord += dx; notifyObservers(); }
        void moveY(int dy) { yCoord += dy; notifyObservers(); }
        int getHp() const { return hp; }
        int getAtk() const { return atk; }
        int getDef() const { return def; }
        virtual char charAt(int row, int col, int tick) = 0;
        virtual void attack(Player& pc) = 0;
};

class Human : public Enemy {
        int randNum1 = std::rand() % 79;
        int randNum2 = std::rand() % 30;
    public:
        Human(AsciiArt *next, int xCoord, int yCoord, int hp, int atk, int def) 
            : {Decorator}next { 
            HumanObserver(this, randNum1, randNum2); 
        }
        char charAt(int row, int col, int tick) override;
        void attack(Player& pc) override;
};

char Human::charAt(int row, int col, int tick) {
    if (row == xCoord && col == yCoord) return 'H'; 
    return next->charAt(row, col, tick); 
}

void Human::attack(Player& pc) {
    pc.loseHP(Human::getAtk());
}


// class Dwarf : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Dwarf() { randNum1; randNum2; hp = 100; atk = 20; def = 30; }
//         void attack(Player& pc) override;
// };

// class Elf : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Elf() { randNum1; randNum2; hp = 140; atk = 30; def = 10; }
//         void attack(Player& pc) override;
// };

// class Orc : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Orc() { randNum1; randNum2; hp = 180; atk = 30; def = 25; }
//         void attack(Player& pc) override;
// };

// class Merchant : public Enemy {
//         int randNum1 = std::rand() % 79;
//         int randNum2 = std::rand() % 30;
//     public:
//         Merchant() { randNum1; randNum2; hp = 30; atk = 70; def = 5; }
//         void attack(Player& pc) override;
// };

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

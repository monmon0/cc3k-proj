#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include <string>

class Player : public Decorator {
    char race;
    int x, y;                         // Current Position
    int hp, atk, def;                // Current Stat

    public:
    // Constructor and destructor 
    Player(char race, AsciiArt *next, int x, int y, int hp, int atk, int def); 
    ~Player();
    char charAt(int row, int col, int tick) override;
    void move(std::string dir, int tick);
    void loseHP(int x);
    virtual void attack() = 0;      // Attack
    int getAtk();
    int getDef();
    void addHP();
    int getX();
    int getY();

     // Factory Method to create players
    static std::unique_ptr<Player> createPlayer(char race, AsciiArt *next, int x, int y, int hp, int atk, int def);

}; 

class Shade : public Player {
public:
    Shade(AsciiArt *next, int x, int y, int hp, int atk, int def);
    void attack() override;
};

class Drow : public Player {
public:
    Drow(AsciiArt *next, int x, int y, int hp, int atk, int def);
    void attack() override;
};

class Vampire : public Player {
    public:
        Vampire(AsciiArt *next, int x, int y, int hp, int atk, int def);
        void attack() override;
};

class Goblin : public Player {
public:
    Goblin(AsciiArt *next, int x, int y, int hp, int atk, int def);
    void attack() override;
};

#endif // PLAYERS_H

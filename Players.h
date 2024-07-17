#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include<string>

class Player : public Decorator {
    char race;
    int x, y;                         // Current Position
    int hp, atk, def;                // Current Stat
    // virtual void attack() = 0;   // Attack

    public:
    // Constructor and destructor 
    Player(char race, AsciiArt *next, int x, int y); 
    char charAt(int row, int col, int tick) override;
    void move(std::string dir, int tick);
    void loseHP(int x);
}; 

class Shade: public Player {
    
};

class Drow: public Player {
    

};


class Vampire: public Player {
    
};

class Goblin: public Player {
    
};

#endif // PLAYERS_H

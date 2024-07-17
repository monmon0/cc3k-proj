#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include <vector>
#include <string>
#include "Observer.h"
#include <memory>

class Player : public Decorator {
    char race;
    int x, y;                         // Current Position
    int hp, atk, def;                // Current Stat
    std::vector<Observer *> potions;

    public:
    // Constructor and destructor 
    Player(char race, AsciiArt *next, int x, int y, int hp, int atk, int def); 
    ~Player();
    char charAt(int row, int col, int tick) override;
    void move(std::string dir, int tick);
    void loseHP(int x);
    void attack();      // Attack

    int getAtk(int x) { return atk; };
    int getDef(int x) { return def; };
    void addHP(int x) { hp += x;};;
    void addAtk(int x) { atk += x;};;
    void addDef(int x) { def += x;};

    int getX() {return x;};
    int getY() {return y;};

    void attach(Observer * o) {
        potions.emplace_back(o);
    };

    void detach(Observer* o) {
        for (auto it = potions.begin(); it != potions.end(); ++it) {
            if (*it == o) {
                potions.erase(it);
                break;
            }
        }
    };

    void notifyPotion() {
        for (auto o: potions) o->notify();
    };

}; 

#endif // PLAYERS_H

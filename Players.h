#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include <vector>
#include "Potion.h"
#include "Observer.h"
#include <string>

class Player : public Decorator {

    protected:
        char race;
        int x, y;                         // Current Position
        int hp, atk, def, max_hp;         // Current Stat
        int gold = 0, floor = 1;
        std::string announcement;

        std::vector <Observer * > potions;

    public:
    // Constructor and destructor 
        Player(char race, AsciiArt *next, int x, int y, int hp, int atk, int def); 
        char charAt(int row, int col, int tick) override;
        void move(std::string dir, AsciiArt *next);
        char getRace() {return race;}

        std::string getAnnouncement() {return announcement;}
        int getAtk() { return atk; }
        int getDef() { return def; }
        int getHP()  { return hp; }
        int getGold(){ return gold; }
        int getFlr() { return floor; }

        void changeHP(int x) { hp += x;}
        void changeAtk(int x) { atk += x;}
        void changeDef(int x) { def += x;}
        std::string dirToString(std::string dir);

        int getMaxHP() {return max_hp;}
        int getX() {return x;}
        int getY() {return y;}

        void attack(std::string dir);      // Attack 
        void takePotion();

    void attach(Observer * o) {
            potions.emplace_back(o);
        }

        void detach(Observer* o) {
            for (auto it = potions.begin(); it != potions.end(); ++it) {
                if (*it == o) {
                    potions.erase(it);
                    break;
                }
            }
        }

}; 

// -------------------------- Derived Class of other PC -------------------------- //

class Shade : public Player {
    public:
        Shade(char race, AsciiArt *next, int x, int y, int hp, int atk, int def):
           Player(race, next, x, y, hp, atk, def) {
            announcement = "Player chooses Shade.";
           };
};

class Troll : public Player {
    public:
        Troll(char race, AsciiArt *next, int x, int y, int hp, int atk, int def):
           Player(race, next, x, y, hp, atk, def) {
                announcement = "Player chooses Troll.";
           };
};

class Drow : public Player {
    public:
        Drow(char race, AsciiArt *next, int x, int y, int hp, int atk, int def):
           Player(race, next, x, y, hp, atk, def) {
            announcement = "Player chooses Drow.";
           };
};

class Goblin : public Player {
    public:
        Goblin(char race, AsciiArt *next, int x, int y, int hp, int atk, int def):
           Player(race, next, x, y, hp, atk, def) {
            announcement = "Player chooses Goblin.";
           };
};


class Vampire : public Player {
    public:
        Vampire(char race, AsciiArt *next, int x, int y, int hp, int atk, int def):
           Player(race, next, x, y, hp, atk, def) {
            announcement = "Player chooses Vampire.";
           };
};


#endif // PLAYERS_H

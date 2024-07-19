#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include <vector>
#include "Potion.h"
#include "character.h"
#include <string>

class Potion;

class Player : public Character {

    protected:
        int max_hp;         // Current Stat
        int gold = 0;
        std::vector <Potion * > potions;
        bool levelUp;                       // check if at staircase

    public:
    // Constructor and destructor 
        Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);
        ~Player() = default;
        char charAt(int row, int col, int tick) override;
        void move(std::string dir, AsciiArt *next);
        char getRace() {return race;}

        std::string getAnnouncement() {return announcement;}

        void changeAtk(int x) { atk += x;}
        void changeDef(int x) { def += x;}
        std::string dirToString(std::string dir);

        int getMaxHP() {return max_hp;}
        int getGold() const { return gold; }
        
        bool attack(std::string dir);      // Attack 
        void takePotion();

        bool isLevelUp() const;
        void attach(Potion * o);
        void detach(Potion* o);

}; 

// -------------------------- Derived Class of other PC -------------------------- //

class Shade : public Player {
    public:
        Shade(AsciiArt *next, char race, int x, int y, int hp, int atk, int def):
            Player(next, race, x, y, hp, atk, def) {
            announcement = "Player chooses Shade.";
           };
};

class Troll : public Player {
    public:
        Troll(AsciiArt *next, char race, int x, int y, int hp, int atk, int def):
           Player(next, race, x, y, hp, atk, def)  {
                announcement = "Player chooses Troll.";
            };
};

class Drow : public Player {
    public:
        Drow(AsciiArt *next, char race, int x, int y, int hp, int atk, int def):
           Player(next, race, x, y, hp, atk, def) {
            announcement = "Player chooses Drow.";
           };
};

class Goblin : public Player {
    public:
        Goblin(AsciiArt *next, char race, int x, int y, int hp, int atk, int def):
           Player(next, race, x, y, hp, atk, def) {
            announcement = "Player chooses Goblin.";
           };
};


class Vampire : public Player {
    public:
        Vampire(AsciiArt *next, char race, int x, int y, int hp, int atk, int def):
           Player(next, race, x, y, hp, atk, def)  {
            announcement = "Player chooses Vampire.";
           };
};


#endif // PLAYERS_H

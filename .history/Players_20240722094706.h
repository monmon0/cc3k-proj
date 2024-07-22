#ifndef PLAYERS_H
#define PLAYERS_H
#include "asciiart.h"
#include "decorator.h"
#include <vector>
#include "item.h"
#include "character.h"
#include <string>

class Potion;

class Player : public Character {

    protected:
        int max_hp;         
        int gold = 0;      
        bool levelUp;      
        int new_block_x = 0, new_block_y = 0;
        int hitbyH = 1;
        bool ()
        std::vector <Potion * > potions;

    public:
        // Constructor and destructor 
        Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);
        ~Player() = default;
        char charAt(int row, int col, int tick) override;
        void move(std::string dir, AsciiArt *next);
        char getRace() {return race;}
        void addGold(int amt) {gold += amt;}
        void getHitbyHalfing() {hitbyH = 2;}
        void setAtk(int x) {atk = x;}
        void changeAtk(double x) { atk += x;}
        void changeDef(double x) { def += x;}
        std::string dirToString(std::string dir);

        int getMaxHP() {return max_hp;}
        int getGold() const { return gold;}
        
        bool attack(AsciiArt * d, std::string dir);      // Attack 
        void takePotion(AsciiArt * m, std::string dir);         //  Use Potion
        void nextLevel(int x, int y);        
        void restartSettings(char n_race, int n_hp, int n_atk, int n_def);

        bool isLevelUp() const;
        void attach(Potion * o);
        void detach(Potion* o);
        char atPostion(AsciiArt * d, std::string dir);

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

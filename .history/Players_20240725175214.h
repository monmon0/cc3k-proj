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
        int hitbyH = false;
        bool hitMerchant = false; 
        int location = -1;  
        std::vector <Potion * > potions;
        
    public:

        Player();
        Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location);
        ~Player() = default;
        char charAt(int row, int col) override;
        void move(std::string dir, AsciiArt *next);
        char getRace();
        void addGold(int amt);
        void getHitbyHalfing();
        bool isFriend();
        void setAtk(int x);
        int getLocation();
        void changeAtk(double x);
        void changeDef(double x);

        int getMaxHP();
        int getGold() const;         
        
        bool attack(AsciiArt * d, std::string dir);              // Attack 
        void takePotion(AsciiArt * m, std::string dir);         //  Use Potion
        void nextLevel(int x, int y);        

        bool isLevelUp() const;
        void attach(Potion * o);
        void detach(Potion* o);
        char atPostion(AsciiArt * d, std::string dir);
}; 

#endif // PLAYERS_H

#ifndef CHARACTER_H
#define CHARACTER_H
#include <map>
#include "decorator.h"
#include "asciiart.h"
#include <vector>
#include <string>

class Character : public Decorator {
    protected: 
        char race; 
        int x,y;
        double hp, atk, def;
        std::string announcement;
        std::map<std::string, std::string> dirMap = {{"so", "South"}, {"no", "North"}, {"ea", "East"}, {"we", "West"},
                                                     {"ne", "North East"}, {"nw", "North West"}, {"se", "South East"}, 
                                                     {"sw", "South West"}};
        std::map<char, std::string> raceMap = {{'d', "Drow"},  {'v', "Vampire"}, {'t', "Troll"},
                                               {'g',"Goblin"}, {'s', "Shade"}};

        std::map<char, std::vector<int>> raceAbilities = {{'d', {125,2,3}},  {'v', {125,2,3}}, {'t', {125,2,3}},
                                                        {'g',{125,2,3}}, {'s', {125,2,3}}};


    public:
        Character(AsciiArt *next, char id, int x, int y, double hp, double atk, double def);
        ~Character() = default; 

        int getX() const;
        int getY() const;
        double getHp() const;
        double getAtk() const;
        double getDef() const;
        std::string getAnnouncement() const;
        void changeHP(double damage);
        bool isDead();
        char getRace();
        AsciiArt *&nextChar() {return next;}

        virtual char charAt(int row, int col) = 0;
};

#endif // CHARACTER_H

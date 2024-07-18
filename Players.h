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
    int hp, atk, def, max_hp;         // Current Stat
    int gold = 0, floor = 1;
    std::string announcement;

    public:
    // Constructor and destructor 
    Player(char race, AsciiArt *next, int x, int y, int hp, int atk, int def); 
    ~Player() {}
    char charAt(int row, int col, int tick) override;
    void move(std::string dir);
    char getRace() {return race;}
    void attack(std::string dir);      // Attack

    std::string getAnnouncement() {return announcement;}

    int getAtk() { return atk; }
    int getDef() { return def; }
    int getHP()  { return hp; }
    int getGold(){ return gold; }
    int getFlr() { return floor; }

    void changeHP(int x) { hp += x;}
    void changeAtk(int x) { atk += x;}
    void changeDef(int x) { def += x;}

    int getMaxHP() {return max_hp;}
    int getX() {return x;}
    int getY() {return y;}

}; 

#endif // PLAYERS_H

//   void attach(Observer * o) {
//         potions.emplace_back(o);
//     }

//     void detach(Observer* o) {
//         for (auto it = potions.begin(); it != potions.end(); ++it) {
//             if (*it == o) {
//                 potions.erase(it);
//                 break;
//             }
//         }
//     }

//     void notifyPotion(std::string dir) {
//         // check attack direction
//         int new_x = x, new_y = y;

//         if (dir == "no") {
//             new_y--;
//         } else if (dir == "so") {
//             new_y++;
//         } else if (dir == "ea") {
//             new_x++;
//         } else if (dir == "we") {
//             new_x--;
//         } else if (dir == "ne") {
//             new_x++;
//             new_y--;
//         } else if (dir == "nw") {
//             new_x--;
//             new_y--;
//         } else if (dir == "se") {
//             new_x++;
//             new_y++;
//         }
//         else if (dir == "sw") {
//             new_x--;
//             new_y++;
//         }
//         // for (auto o: potions) o->notify(this, new_x, new_y);
//     }
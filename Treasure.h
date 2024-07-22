#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include "Enemies.h"
#include "item.h"
#include <map>
#include <utility>

class Player;
class Enemies;

class Treasure: public Item {
    protected:
        bool isGuarded;
    public:
        Treasure(AsciiArt *next, int x, int y, double val);
        char charAt(int x, int y, int tick) override;
        void applyEffect(Player *player) override;
};

// class Dragon_Hoard: public Treasure {
//     protected:
//         bool isGuarded;
//         Enemy *dragon;

//     public:
//         Dragon_Hoard(AsciiArt *next, int x, int y, double val, bool isGuarded = true);
//         void applyEffect(Player *player) override;
//         Enemy *getDragon();
// };

#endif

#ifndef TREASURE_H
#define TREASURE_H
#include "Players.h"
#include "decorator.h"
#include "Enemies.h"
#include "item.h"
#include "Observer.h"
#include <map>
#include <utility>

class Player;
class Enemies;

class Treasure: public Item {
    // protected:
    //     Subject *subject;
    //     bool isGuarded;
    public:
        Treasure(AsciiArt *next, int x, int y, double val);
        char charAt(int x, int y, int tick) override;
        void applyEffect(Player *player) override;
};

class Dragon_Hoard: public Treasure, public Observer {
    protected:
        bool isGuarded;
        Subject *dragon;

    public:
        Dragon_Hoard(AsciiArt *next, int x, int y, double val, Subject *dragon);
        void applyEffect(Player *player) override;
        void notify() override;
        // Enemy *getDragon();
};

#endif

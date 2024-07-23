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
        char charAt(int row, int col, int tick) override;
        void applyEffect(Player *player) override;
        // virtual bool collectable();
};

class Dragon_Hoard: public Treasure {
    protected:
        bool isGuarded;

    public:
        Dragon_Hoard(AsciiArt *next, int x, int y);
        void unGuarded();
        void applyEffect(Player *player) override;
        char charAt(int row, int col, int tick) override;
        bool collectable() override;
};

#endif

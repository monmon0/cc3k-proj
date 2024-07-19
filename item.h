#ifndef ITEM_H
#define ITEM_H
#include "Players.h"
#include "decorator.h"
#include <utility>
#include <map>
using namespace std;

class Player;

class Item: public Decorator {
    static inline map<pair<int, int>, Item *> iMap;

    protected:
        int x;
        int y;
        int amt;

    public:
        Item(AsciiArt *next, int x, int y, int amt);
        // char charAt(int x, int y, int tick) override;
        int getAmt();
        virtual void applyEffect(Player *player) = 0;
        static void addItem(int x, int y, Item* item);
        static Item *getItem(int x, int y);
        static void deleteItem(Item *item);
        static void deleteAll();
        int getX();
        int getY();
        AsciiArt *&nextChar();
};


#endif

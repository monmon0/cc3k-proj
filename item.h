#ifndef ITEM_H
#define ITEM_H
#include "Players.h"
#include "decorator.h"
#include <utility>
#include <map>
#include <string>
using namespace std;

class Player;

class Item: public Decorator {
    static inline std::vector<Item *> iVec;

    protected:
        int x;
        int y;
        double amt;
        string announcement = "";
        bool active = true;
        string name;

    public:
        Item(AsciiArt *next, int x, int y, double amt);
        double getAmt();
        string getAnnouncement() const;
        virtual void applyEffect(Player *player) = 0;
        virtual bool collectable();
        static void addItem(Item* item);
        static Item *getItem(int x, int y);
        static void deleteAll();

        int getX();
        int getY();
        AsciiArt *&nextChar();
        string getName() const {return name;}
        void changeActive() {active = false;}

};


#endif

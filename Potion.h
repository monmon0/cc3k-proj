#ifndef POTION_H_
#define POTION_H_

#include "Players.h"
#include "item.h"
#include <string>
#include <utility>
#include <map>
#include <iostream>
using namespace std;

class Player;

class Potion: public Item {

    protected:
        string name;

    public:
        Potion(AsciiArt *next, int x, int y, double amt, string name);
        char charAt(int row, int col) override;
        string getName() const;
        virtual void undoEffect(Player *player);
};

#endif

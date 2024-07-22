#ifndef POTION_H
#define POTION_H

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
        char charAt(int row, int col, int tick) override;
        string getName() const;
        virtual void undoEffect(Player *player) = 0;
};

class RH: public Potion {
    public:
        RH(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override {}
};

class BA: public Potion {
    public:
        BA(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class BD: public Potion {
    public:
        BD(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class PH: public Potion {
    public:
        PH(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override {}
};

class WA: public Potion {
    public:
        WA(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class WD: public Potion {
    public:
        WD(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

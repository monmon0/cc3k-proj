#ifndef POTION_H
#define POTION_H

#include "Observer.h"
#include "Players.h"
#include <string>
#include <utility>
#include <map>
using namespace std;

class Potion: public Decorator, public Observer {
    static inline map<pair<int, int>, Potion *> pMap;

    protected:
        int x;
        int y;
        string name;
        int amt;

    public:
        Potion(AsciiArt *next, int x, int y, string name, int amt);
        virtual void applyEffect(Player *player) = 0;
        virtual void undoEffect(Player *player) = 0;
        char charAt(int x, int y, int tick) override;
        int getAmt();
        static void addPotion(int x, int y, Potion* potion);
        static Potion *getPotion(int x, int y);
        static void deletePotion(Potion *potion);
};

class RH: public Potion {
    public:
        RH(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
};

class BA: public Potion {
    public:
        BA(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class BD: public Potion {
    public:
        BD(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class PH: public Potion {
    public:
        PH(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
};

class WA: public Potion {
    public:
        WA(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

class WD: public Potion {
    public:
        WD(AsciiArt *next, int x, int y, string name, int amt);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

#ifndef BD_H_
#define BD_H_
#include "Potion.h"

class BD: public Potion {
    public:
        BD(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

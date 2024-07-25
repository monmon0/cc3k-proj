#ifndef RH_H_
#define RH_H_

#include "Potion.h"

class RH: public Potion {
    public:
        RH(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
};

#endif

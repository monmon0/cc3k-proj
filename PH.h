#ifndef PH_H_
#define PH_H_
#include "Potion.h"

class PH: public Potion {
    public:
        PH(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
};

#endif

#ifndef WA_H_
#define WA_H_
#include "Potion.h"

class WA: public Potion {
    public:
        WA(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

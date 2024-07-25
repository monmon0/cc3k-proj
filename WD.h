#ifndef WD_H_
#define WD_H_
#include "Potion.h"

class WD: public Potion {
    public:
        WD(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

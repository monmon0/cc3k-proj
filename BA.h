#ifndef BA_H_
#define BA_H_
#include "Potion.h"

class BA: public Potion {
    public:
        BA(AsciiArt *next, int x, int y, string name);
        void applyEffect(Player *player) override;
        void undoEffect(Player *player) override;
};

#endif

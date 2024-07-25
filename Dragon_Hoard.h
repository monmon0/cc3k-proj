#ifndef DRAGON_HOARD_
#define DRAGON_HOARD_

#include "Treasure.h"

class Dragon_Hoard: public Treasure {
    protected:
        bool isGuarded;

    public:
        Dragon_Hoard(AsciiArt *next, int x, int y);
        void unGuarded();
        void applyEffect(Player *player) override;
        char charAt(int row, int col) override;
        bool collectable() override;
};

#endif

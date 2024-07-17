#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "Observer.h"
#include "PotionDecorator.h"
#include "Player.h"
#include <string>

class Potion: public Observer {
    int x;
    int y;
    string name;
    public:
        Potion(int x, int y, string name);
        void notify() override;
        virtual void applyEffect(Player *player);
}

#endif

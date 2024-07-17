#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "Observer.h"
#include "PotionDecorator.h"
#include "Players.h"
#include <string>

class Potion: public Observer {
    int x;
    int y;
    string name;
    public:
        Potion(int x, int y, string name);
        virtual void notify(Players *player) override;
        virtual void applyEffect(Player *player);
}

#endif

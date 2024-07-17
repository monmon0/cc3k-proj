#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "Observer.h"
#include "PotionDecorator.h"
#include <string>

class Potion: public Observer {
    int x;
    int y;
    string name;
    int amt;
}

#endif

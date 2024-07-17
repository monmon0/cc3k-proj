#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "Observer.h"
#include 

class Potion: public Decorator, public Observer {
    int x;
    int y;

}

#endif

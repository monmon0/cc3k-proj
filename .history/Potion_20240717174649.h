#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "observer.h"

class Potion: public Decorator, public Observer {
    int x;
    int y;

}

#endif

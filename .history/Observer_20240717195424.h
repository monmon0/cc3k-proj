#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "players.h"

class Observer {
    public:
        virtual void notify(Player * p, int x, int y) = 0;
        virtual void notify() = 0;
        virtual ~Observer() = default;
};

#endif

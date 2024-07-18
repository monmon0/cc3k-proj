#ifndef _OBSERVER2_H_
#define _OBSERVER2_H_
#include "players.h"

class Observer {
    public:
        virtual void notify(Player * p, int x, int y) = 0;
        virtual ~Observer() = default;
};

#endif

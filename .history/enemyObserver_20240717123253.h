#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
#include "Observer.h"

class EnemyObserver : public Observer {
        std::vector<char> surroundings;

    protected: 
        int hp;
        int atk;
        int def;

    public:
        Writer(Studio *studio, int t, int b, int l, int r);
        void notify() override;
        ~Writer();
};

#endif

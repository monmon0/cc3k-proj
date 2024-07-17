#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
#include "Subject.h"
#include "Observer.h"
#include "enemies.h"

#include <memory>

class EnemyObserver : public Observer {
    protected: 
        auto surroundings = std::make_unique<char []> ( 8 );
        Enemy *subject;
        int xCoord;
        int yCoord;

    public:
        EnemyObserver(Enemy *enemy, int x, int y);
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
            // CHANGE THE CONTENT IN SURROUNDINGS
        }
        ~EnemyObserver() = default; 
};

EnemyObserver::EnemyObserver(Enemy *enemy, int x, int y) 
    : subject{enemy}, xCoord{x}, yCoord{y} {
    subject->attach(this);
}

EnemyObserver::~EnemyObserver() {
    subject->detach(this); 
}

#endif

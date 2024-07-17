#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
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
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
            // CHANGE THE CONTENT IN SURROUNDINGS
        }
        ~EnemyObserver() = default; 
};


#endif

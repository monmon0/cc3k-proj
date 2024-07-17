#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
#include "Observer.h"

class EnemyObserver : public Observer {
    protected: 
        std::vector<char> surroundings;
        Enemy *subject;
        int xCoord;
        int yCoord;

    public:
        void notify() override;
        ~EnemyObserver() = default; 
};

class HumanObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

class DwarfObserver : public EnemyObserver {
    public:
        DwarfObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~DwarfObserver() {
            subject->detach(this); 
        }
};

class ElfObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

class OrcObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

class MerchantObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

class DragonObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

class HalflingObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 
        }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

#endif 

#endif

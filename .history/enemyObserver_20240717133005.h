#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
#include "Observer.h"

class EnemyObserver : public Observer {
    protected: 
        auto surroundings = std::make_unique<YourType []> ( size );
        Enemy *subject;
        int xCoord;
        int yCoord;

    public:
        void notify() override {
            xCoord = subject->getX(); 
            yCoord = subject->getY(); 

        }
        ~EnemyObserver() = default; 
};

class HumanObserver : public EnemyObserver {
    public:
        HumanObserver(Enemy *enemy, int x, int y) 
            : subject{enemy}, xCoord{x}, yCoord{y} {
                subject->attach(this);
            }
        ~HumanObserver() {
            subject->detach(this); 
        }
};

// class DwarfObserver : public EnemyObserver {
//     public:
//         DwarfObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~DwarfObserver() {
//             subject->detach(this); 
//         }
// };

// class ElfObserver : public EnemyObserver {
//     public:
//         ElfObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~ElfObserver() {
//             subject->detach(this); 
//         }
// };

// class OrcObserver : public EnemyObserver {
//     public:
//         OrcObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~OrcObserver() {
//             subject->detach(this); 
//         }
// };

// class MerchantObserver : public EnemyObserver {
//     public:
//         MerchantObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~MerchantObserver() {
//             subject->detach(this); 
//         }
// };

// class DragonObserver : public EnemyObserver {
//     public:
//         DragonObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~DragonObserver() {
//             subject->detach(this); 
//         }
// };

// class HalflingObserver : public EnemyObserver {
//     public:
//         HalflingObserver(Enemy *enemy, int x, int y) 
//             : subject{enemy}, xCoord{x}, yCoord{y} {
//                 subject->attach(this);
//             }
//         void notify() override {
//             xCoord = subject->getX(); 
//             yCoord = subject->getY(); 
//         }
//         ~HalflingObserver() {
//             subject->detach(this); 
//         }
// };

#endif

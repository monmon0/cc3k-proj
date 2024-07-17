#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H
#include "Observer.h"

class EnemyObserver : public Observer {
        std::vector<char> surroundings;

    protected: 
        int xCoord;
        int yCoord;

    public:
        void notify() override;
        ~EnemyObserver();
};

class HumanObserver : public EnemyObserver {
    public:
        HumanObserver() { hp = 140; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class DwarfObserver : public EnemyObserver {
    public:
        DwarfObserver() { hp = 100; atk = 20; def = 30; }
        void attack(Player& pc) override;
};

class ElfObserver : public EnemyObserver {
    public:
        ElfObserver() { hp = 140; atk = 30; def = 10; }
        void attack(Player& pc) override;
};

class OrcObserver : public EnemyObserver {
    public:
        OrcObserver() { hp = 180; atk = 30; def = 25; }
        void attack(Player& pc) override;
};

class MerchantObserver : public EnemyObserver {
    public:
        MerchantObserver() { hp = 30; atk = 70; def = 5; }
        void attack(Player& pc) override;
};

class DragonObserver : public EnemyObserver {
    public:
        DragonObserver() { hp = 150; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class HalflingObserver : public EnemyObserver {
    public:
        HalflingObserver() { hp = 100; atk = 15; def = 20; }
        void attack(Player& pc) override;
};

#endif 

#endif

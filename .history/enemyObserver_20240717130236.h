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
        HumanObse() { hp = 140; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class DwarfObserver : public EnemyObserver {
    public:
        DwarfObse() { hp = 100; atk = 20; def = 30; }
        void attack(Player& pc) override;
};

class ElfObserver : public EnemyObserver {
    public:
        ElfObse() { hp = 140; atk = 30; def = 10; }
        void attack(Player& pc) override;
};

class OrcObserver : public EnemyObserver {
    public:
        OrcObse() { hp = 180; atk = 30; def = 25; }
        void attack(Player& pc) override;
};

class MerchantObserver : public EnemyObserver {
    public:
        MerchantObse() { hp = 30; atk = 70; def = 5; }
        void attack(Player& pc) override;
};

class DragonObserver : public EnemyObserver {
    public:
        DragonObse() { hp = 150; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class HalflingObserver : public EnemyObserver {
    public:
        HalflingObse() { hp = 100; atk = 15; def = 20; }
        void attack(Player& pc) override;
};

#endif 

#endif

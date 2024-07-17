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
        Human() { hp = 140; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class DwarfObserver : public EnemyObserver {
    public:
        Dwarf() { hp = 100; atk = 20; def = 30; }
        void attack(Player& pc) override;
};

class ElfObserver : public EnemyObserver {
    public:
        Elf() { hp = 140; atk = 30; def = 10; }
        void attack(Player& pc) override;
};

class OrcObserver : public EnemyObserver {
    public:
        Orc() { hp = 180; atk = 30; def = 25; }
        void attack(Player& pc) override;
};

class MerchantObserver : public EnemyObserver {
    public:
        Merchant() { hp = 30; atk = 70; def = 5; }
        void attack(Player& pc) override;
};

class DragonObserver : public EnemyObserver {
    public:
        Dragon() { hp = 150; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class HalflingObserver : public EnemyObserver {
    public:
        Halfling() { hp = 100; atk = 15; def = 20; }
        void attack(Player& pc) override;
};

#endif 

#endif

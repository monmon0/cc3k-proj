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

class HumanObserver : public Enemy {
    public:
        Human() { hp = 140; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class DwarfObserver : public Enemy {
    public:
        Dwarf() { hp = 100; atk = 20; def = 30; }
        void attack(Player& pc) override;
};

class ElfObserver : public Enemy {
    public:
        Elf() { hp = 140; atk = 30; def = 10; }
        void attack(Player& pc) override;
};

class OrcObserver : public Enemy {
    public:
        Orc() { hp = 180; atk = 30; def = 25; }
        void attack(Player& pc) override;
};

class MerchantObserver : public Enemy {
    public:
        Merchant() { hp = 30; atk = 70; def = 5; }
        void attack(Player& pc) override;
};

class DragonObserver : public Enemy {
    public:
        Dragon() { hp = 150; atk = 20; def = 20; }
        void attack(Player& pc) override;
};

class HalflingObserver : public Enemy {
    public:
        Halfling() { hp = 100; atk = 15; def = 20; }
        void attack(Player& pc) override;
};

#endif 

#endif

#ifndef ENEMYOBSERVER_H
#define ENEMYOBSERVER_H

class Enemy : public Subject {
        std::vector<char> surroundings;

    protected: 
        int hp;
        int atk;
        int def;

    public:
        virtual ~Enemy() {}
        int getHp() const { return hp; }
        int getAtk() const { return atk; }
        int getDef() const { return def; }
        virtual void attack(Player& pc) = 0;
};

#endif

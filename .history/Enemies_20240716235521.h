#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class PlayerCharacter;  // wait for mon's PC class name here

class Enemy {
protected:
    int hp;
    int atk;
    int def;

public:
    virtual ~Enemy() {}
    int getHp() const { return hp; }
    int getAtk() const { return atk; }
    int getDef() const { return def; }
    virtual void attack(PlayerCharacter& pc) = 0;
};

class Human : public Enemy {
public:
    Human() { hp = 140; atk = 20; def = 20; }
    void attack(PlayerCharacter& pc) override;
};

class Dwarf : public Enemy {
public:
    Dwarf() { hp = 100; atk = 20; def = 30; }
    void attack(PlayerCharacter& pc) override;
};

class Elf : public Enemy {
public:
    Elf() { hp = 140; atk = 30; def = 10; }
    void attack(PlayerCharacter& pc) override;
};

class Orc : public Enemy {
public:
    Orc() { hp = 180; atk = 30; def = 25; }
    void attack(PlayerCharacter& pc) override;
};

class Merchant : public Enemy {
public:
    Merchant() { hp = 30; atk = 70; def = 5; }
    void attack(PlayerCharacter& pc) override;
};

class Dragon : public Enemy {
public:
    Dragon() { hp = 150; atk = 20; def = 20; }
    void attack(PlayerCharacter& pc) override;
};

class Halfling : public Enemy {
public:
    Halfling() { hp = 100; atk = 15; def = 20; }
    void attack(PlayerCharacter& pc) override;
};

#endif // ENEMY_H
b
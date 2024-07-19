#include "character.h"

Character::Character(AsciiArt *next, char id, int x, int y, int hp, int atk, int def)
    : Decorator{next}, race{id}, x{x}, y{y}, hp{hp}, atk{atk}, def{def} {}

int Character::getX() const { return x; }
int Character::getY() const { return y; }
int Character::getHp() const { return hp; }
int Character::getAtk() const { return atk; }
int Character::getDef() const { return def; }
std::string Character::getAnnouncement() const { return announcement; }
void Character::changeHP(int damage) { hp -= damage; }
bool Character::isDead() { return hp <= 0; }
char Character::getRace() { return race; }

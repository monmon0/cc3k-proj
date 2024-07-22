#include "character.h"

Character::Character(AsciiArt *next, char id, int x, int y, double hp, double atk, double def)
    : Decorator{next}, race{id}, x{x}, y{y}, hp{hp}, atk{atk}, def{def} {}

int Character::getX() const { return x; }
int Character::getY() const { return y; }
double Character::getHp() const { return hp; }
double Character::getAtk() const { return atk; }
double Character::getDef() const { return def; }
std::string Character::getAnnouncement() const { return announcement; }
void Character::changeHP(double damage) { hp += damage; }
bool Character::isDead() { return hp <= 0; }
char Character::getRace() { return race; }

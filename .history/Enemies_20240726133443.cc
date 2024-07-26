#include "Enemies.h"

#include <iostream>

// Implement the Enemy constructor
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Implement the virtual charAt method
char Enemy::charAt(int row, int col) {
    if (col == x && row == y && !isDead()) {
        return getRace(); 
    } else {
        return next->charAt(row, col); 
    }
}

bool Enemy::isDead() const { return hp <= 0; } 

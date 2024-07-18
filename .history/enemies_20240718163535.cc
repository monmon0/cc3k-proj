#include "Enemies.h"

// Enemy class implementation
Enemy::Enemy(AsciiArt *next, char id, int x, int y, int hp, int atk, int def)
    : Decorator(next), ID{id}, xCoord{x}, yCoord{y}, hp{hp}, atk{atk}, def{def} {}

// Human class implementation
Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {
}

char Human::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Dwarf class implementation
Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'W', xCoord, yCoord, 100, 20, 30) {
}

char Dwarf::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Elf class implementation
Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {
}

char Elf::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Orc class implementation
Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {
}

char Orc::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Merchant class implementation
Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {
}

char Merchant::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Dragon class implementation
Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'D', xCoord, yCoord, 150, 20, 20) {
}

char Dragon::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

// Halfling class implementation
Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {
}

char Halfling::charAt(int row, int col, int tick) {
    if (row == yCoord && col == xCoord) return getState(); 
    return next->charAt(row, col, tick); 
}

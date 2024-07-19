#include "Enemies.h"

char Enemy::charAt(int row, int col, int tick) {
    if (col == x && row == y) {
        char id = getRace(); 
        if (id == 'H') return 'H'; 
        else if (id == 'W') return 'W'; 
        else if (id == 'E') return 'E'; 
        else if (id == 'O') return 'O';
        else if (id == 'M') return 'M';
        else if (id == 'D') return 'D'; 
        else if (id == 'L') return 'L'; 
    } else {
        return charAt(row, col, tick); 
    }
}

// Enemy class implementation
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def
    : Character(next, race, x, y, hp, atk, def) {}

#include "Enemies.h"

// Implement the Enemy constructor
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Implement the virtual charAt method
char Enemy::charAt(int row, int col, int tick) {
    // Implement the method if required
    return ' '; // Placeholder implementation
}

// Implement constructors for derived classes
Human::Human(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'H', xCoord, yCoord, 140, 20, 20) {}

Dwarf::Dwarf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'D', xCoord, yCoord, 100, 20, 30) {}

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {}

Orc::Orc(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'O', xCoord, yCoord, 180, 30, 25) {}

Merchant::Merchant(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'M', xCoord, yCoord, 30, 70, 5) {}

Dragon::Dragon(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'R', xCoord, yCoord, 150, 20, 20) {}

Halfling::Halfling(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'L', xCoord, yCoord, 100, 15, 20) {}

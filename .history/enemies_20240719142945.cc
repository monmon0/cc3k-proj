#include "Enemies.h"

char Enemy::charAt(int row, int col, int tick) {
    if (col == x && row == y) {
        char id = getRace(); 
        if (d == 'H') return 'H'; 
        else if (d == 'W') return 'W'; 
        else if (d == 'E') return 'E'; 
        else if (d == 'O') return 'O';
        else if (d == 'M') return 'M';
        else if (d == 'D') return 'D'; 
        else if (d == 'L') return 'L'; 
    } else {
        return charAt(row, col, tick); 
    }
}

// Enemy class implementation
Enemy::Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def)
    : Character(next, race, x, y, hp, atk, def) {}

// Human class implementation
Human::Human(AsciiArt *next, int x, int y)
    : Enemy(next, 'H', x, y, 140, 20, 20) {
}

// Dwarf class implementation
Dwarf::Dwarf(AsciiArt *next, int x, int y)
    : Enemy(next, 'W', x, y, 100, 20, 30) {
}

// Elf class implementation
Elf::Elf(AsciiArt *next, int x, int y)
    : Enemy(next, 'E', x, y, 140, 30, 10) {
}

// Orc class implementation
Orc::Orc(AsciiArt *next, int x, int y)
    : Enemy(next, 'O', x, y, 180, 30, 25) {
}

// Merchant class implementation
Merchant::Merchant(AsciiArt *next, int x, int y)
    : Enemy(next, 'M', x, y, 30, 70, 5) {
}

// Dragon class implementation
Dragon::Dragon(AsciiArt *next, int x, int y)
    : Enemy(next, 'D', x, y, 150, 20, 20) {
}

// Halfling class implementation
Halfling::Halfling(AsciiArt *next, int x, int y)
    : Enemy(next, 'L', x, y, 100, 15, 20) {
}

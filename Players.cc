#include "players.h"
#include "decorator.h"
#include <iostream>
#include<string>

Player::Player(char race, AsciiArt * next, int x, int y, int hp, int atk, int def): 
    Decorator{next}, x{x}, y{y}, hp{hp}, atk{atk}, def{def}, race{race} {
}

// Factory Method implementation
std::unique_ptr<Player> Player::createPlayer(char race, AsciiArt *next, int x, int y, int hp, int atk, int def) {
    switch (race) {
        case 'S':
            return std::make_unique<Shade>(next, x, y, hp, atk, def);
        case 'D':
            return std::make_unique<Drow>(next, x, y, hp, atk, def);
        case 'V':
            return std::make_unique<Vampire>(next, x, y, hp, atk, def);
        case 'G':
            return std::make_unique<Goblin>(next, x, y, hp, atk, def);
        default:
            throw std::invalid_argument("Invalid player race");
    }
}

// Method implementations for Shade, Drow, Vampire, and Goblin
Shade::Shade(AsciiArt *next, int x, int y, int hp, int atk, int def)
    : Player('S', next, x, y, hp, atk, def) {}

void Shade::attack() {
    // Shade-specific attack implementation
}

Drow::Drow(AsciiArt *next, int x, int y, int hp, int atk, int def)
    : Player('D', next, x, y, hp, atk, def) {}

void Drow::attack() {
    // Drow-specific attack implementation
}

Vampire::Vampire(AsciiArt *next, int x, int y, int hp, int atk, int def)
    : Player('V', next, x, y, hp, atk, def) {}

void Vampire::attack() {
    // Vampire-specific attack implementation
}

Goblin::Goblin(AsciiArt *next, int x, int y, int hp, int atk, int def)
    : Player('G', next, x, y, hp, atk, def) {}

void Goblin::attack() {
    // Goblin-specific attack implementation
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

void Player::loseHP(int x) { hp -= x; }

void Player::move(std::string dir, int tick) {
    // no,so,ea,we,ne,nw,se,sw
    // new block 
    int new_block_x = 0;
    int new_block_y = 0;
    char pos_check = ' ';

    if (dir == "no") {
        new_block_y--;
    } else if (dir == "so") {
        new_block_y++;
    } else if (dir == "ea") {
        new_block_x++;
    } else if (dir == "we") {
        new_block_x--;
    } else if (dir == "ne") {
        new_block_x++;
        new_block_y--;
    } else if (dir == "nw") {
        new_block_x--;
        new_block_y--;
    } else if (dir == "se") {
        new_block_x++;
        new_block_y++;
    }
    else if (dir == "sw") {
        new_block_x--;
        new_block_y++;
    }

    pos_check = next->charAt(y + new_block_y, x + new_block_x, tick);
    if (pos_check != '-' && pos_check != '|' && pos_check != ' ') {
        x += new_block_x;
        y += new_block_y;
    }
}

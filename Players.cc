#include "Players.h"
#include "decorator.h"
#include <iostream>
#include <string>

Player::Player(char race, AsciiArt * next, int x, 
    int y, int hp, int atk, int def): 
    Decorator{next}, race{race} ,x{x}, y{y}, hp{hp}, atk{atk}, def{def}{
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

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

#include "players.h"
#include "decorator.h"
#include <iostream>
#include<string>

Player::Player(char race, AsciiArt * next): Decorator{next}, race{race} {
    x = 6, y = 10;
    hp = 10, atk = 10, def = 10;
}

char Player::charAt(int row, int col, int tick) {
    if (row == x && col == y) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

void Player::move(std::string dir, int tick) {
    // no,so,ea,we,ne,nw,se,sw

    // new block 
    int new_block = 8;

    if (dir == "no") {
        char pos_check = next->charAt(x, y - new_block, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x, y - new_block, tick);
        }
        y -= new_block;

    } else if (dir == "so") {
        char pos_check = next->charAt(x, y + new_block, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x, y + new_block, tick);
        }
        y -= new_block;
    } else if (dir == "ea") {
        char pos_check = next->charAt(x + new_block, y, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x + new_block, y, tick);
        }
        x += new_block;
    } else if (dir == "we") {
         char pos_check = next->charAt(x - new_block, y, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x - new_block, y, tick);
        }
        x -= new_block;
    }  else if (dir == "ne") {
         char pos_check = next->charAt(x + new_block, y - new_block, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x - new_block, y, tick);
        }
        x -= new_block;
    }  else if (dir == "nw") {
         char pos_check = next->charAt(x - new_block, y, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x - new_block, y, tick);
        }
        x -= new_block;
    }  else if (dir == "se") {
         char pos_check = next->charAt(x - new_block, y, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x - new_block, y, tick);
        }
        x -= new_block;
    }  else if (dir == "sw") {
         char pos_check = next->charAt(x - new_block, y, tick);

        while ((pos_check != '.' || pos_check != '#' || pos_check == '\\') && new_block > 0) {
            new_block--;
            pos_check = next->charAt(x - new_block, y, tick);
        }
        x -= new_block;
    }
    std::cout << x << y << std::endl;
}
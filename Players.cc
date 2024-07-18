#include "Players.h"
#include "decorator.h"
#include <iostream>
#include <string>

Player::Player(char race, AsciiArt * next, int x, 
    int y, int hp, int atk, int def): 
    Decorator{next}, race{race} ,x{x}, y{y}, hp{hp}, atk{atk}, def{def}{
        if (race != 'v') {
            max_hp = INT_MAX;
        } else {
            max_hp = hp;
        }
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

void Player::attack(std::string dir) {
    // s, d, v, g, t
    // has enemies
    //  Damage(Def ender) = ceiling((100/(100 + Def (Def ender))) ∗ Atk(Attacker)),
    // (H)uman, d(W)arf, (E)lf, (O)rc, (M)erchant, (D)ragon, Half(L)ing.
    int cor_x = 0;
    int cor_y = 0;
    int found = 0;
    // specify opponent
    for (; cor_x <= 8; cor_x++) {
        for (; cor_y <= 8; cor_y++) {
            char curr = next->charAt(y + cor_y, x + cor_x, 1);
            if (curr == 'H' || curr == 'W' || curr == 'O' || curr == 'M' || curr == 'D' || curr == 'L') {
                found = 1;
                break;
            };
        }
    }
    if (found) {
        if (race == 's') {
            // deal damage to opponent
            
        } else if (race == 'd') {

        } else if (race == 'v') {
            
        } else if (race == 'g') {
            
        } else if (race == 't') {
            
        }
    } else {
        // move dir
        this->move(dir);
    }
    
}

void Player::move(std::string dir) {
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

    pos_check = next->charAt(y + new_block_y, x + new_block_x, 1);
    if (pos_check != '-' && pos_check != '|' && pos_check != ' ') {
        x += new_block_x;
        y += new_block_y;
    }
    // troll gains 5 hp every turn
    if (race == 't') {
        hp += 5;
    }

    // check for staircase
}

#include "Players.h"
#include "decorator.h"
#include <iostream>
#include <map>
#include <string>

Player::Player(char race, AsciiArt * next, int x, int y, int hp, int atk, int def): 
    Decorator{next}, race{race} ,x{x}, y{y}, hp{hp}, atk{atk}, def{def} {
        if (race != 'v') {
            max_hp = INT_MAX;
        } else {
            max_hp = hp;
        }
}

void Player::move(std::string dir) {
    // no,so,ea,we,ne,nw,se,sw
    // new block 
    announcement = "";
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

    // if (pos_check == '.' || pos_check == '#' || pos_check == '\\') {
    //     x += new_block_x;
    //     y += new_block_y;
    //     // announcement = "PC moves " dirToString(dir);
    // }

    // troll gains 5 hp every turn
    if (race == 't') {
        if (max_hp > hp) hp += 5;
        else hp = max_hp;
    }
    // check to see if theres unknown potion?

    // check for staircase
    if (pos_check == '\\') {
        // clear tempo effect, change level, level 5
        // clear all levels enemies, clear all potions
        // regenerate new enemies, generate potions
        floor++;
    }
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

void Player::attack(std::string dir) {
    //  Damage(Def ender) = ceiling((100/(100 + Def (Def ender))) ∗ Atk(Attacker))
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
        int damage = 0;
        announcement = "PC deals " + damage " damage to " curr + "(? HP)";
        // deal damage to opponent

        // increase HP for vampire after sucessful attack
        if (race == 'v')  hp += 5;
    }
    else {
        move(dir);
        announcement = "Player moves " + dirToString(dir);
    }
};

std::string Player::dirToString(std::string dir) {
    std::map<std::string, std::string> dirMap;
    dirMap["so"] = "South";
    dirMap["no"] = "North";
    dirMap["ea"] = "East";
    dirMap["we"] = "West";
    dirMap["no"] = "North East";
    dirMap["nw"] = "North West";
    dirMap["se"] = "South West";
    dirMap["se"] = "South East";
    
    return *dirMap.find(dir);
}


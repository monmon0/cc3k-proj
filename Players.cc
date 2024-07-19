#include "Players.h"
#include "decorator.h"
#include <iostream>
#include <map>
#include "Potion.h"
#include <string>

Player::Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def): 
    Character(next, race, x, y, hp, atk, def) {
        if (race != 'v') max_hp = INT_MAX;
        else max_hp = hp;
}


void Player::move(std::string dir, AsciiArt * curr) {
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

    pos_check = curr->charAt(y + new_block_y, x + new_block_x, 1);

    if (pos_check == '.' || pos_check == '#' || pos_check == '\\' || pos_check == '+') {
        x += new_block_x;
        y += new_block_y;
        announcement = "PC moves " + dirToString(dir);
    }

    // troll gains 5 hp every turn
    if (race == 't') {
        if (max_hp > hp) hp += 5;
        else hp = max_hp;
    }

    // check for staircase
    if (pos_check == '\\') {
        // notify the gameplay
    }
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

bool Player::attack(std::string dir) {
    //  Damage(Def ender) = ceiling((100/(100 + Def (Def ender))) ∗ Atk(Attacker))
    int cor_x = 0;
    int cor_y = 0;
    int found = 0;
    // specify opponent
    for (; cor_x <= 8 && x + cor_x < 79; cor_x++) {
        for (; cor_y <= 8 && y + cor_y < 25; cor_y++) {
            char curr = next->charAt(y + cor_y, x + cor_x, 1);
            if (curr == 'H' || curr == 'W' || curr == 'O' || curr == 'M' || curr == 'D' || curr == 'L') {
                found = 1;
                break;
            };
        }
    }
    if (found) {
        int damage = 0;
        announcement = "PC deals " + std::to_string(damage) + " damage to " + "(? HP)";
        // deal damage to opponent
        
        // increase HP for vampire after sucessful attack
        if (race == 'v')  hp += 5;
        return 1;
    }
    else {
        announcement = "PC didn't attack successfully. ";
        return 0;
    }
};

std::string Player::dirToString(std::string dir) {
    std::map<std::string, std::string> dirMap;
    dirMap["so"] = "South";
    dirMap["no"] = "North";
    dirMap["ea"] = "East";
    dirMap["we"] = "West";
    dirMap["ne"] = "North East";
    dirMap["nw"] = "North West";
    dirMap["sw"] = "South West";
    dirMap["se"] = "South East";
    
    return dirMap[dir];
}

void Player::takePotion() {
    // Potion * p = getPotion(10,)
}

void Player::attach(Potion * o) {
    potions.emplace_back(o);
}

void Player::detach(Potion* o) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (*it == o) {
            potions.erase(it);
            break;
        }
    }
}
bool Player::isLevelUp() const { return levelUp;}
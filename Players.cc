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
        // notify to level up!
        levelUp = true;
    }
}

void Player::restartSettings(char n_race, int n_hp, int n_atk, int n_def) {
    race = race;
    hp = n_hp;
    atk = n_atk;
    def = n_def;
    gold = 0;
    hp = hp;
    if (race == 'v') max_hp = INT_MAX;
    else max_hp = hp;

    for (auto it = potions.begin(); it != potions.end(); ++it) {
        potions.erase(it);
    }
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

bool Player::attack(bool hit) {
    if (hit && race == 'v') hp += 5; 
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

void Player::takePotion(Potion * p) {
    // magnified effects x 1.5
    p->applyEffect(this);
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

bool Player::isLevelUp() const {return levelUp;}

void Player::nextLevel(int n_x, int n_y) {
    levelUp = false;
    x = n_x;
    y = n_y;
    // delete temporary potions
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        potions.erase(it);
    }
}
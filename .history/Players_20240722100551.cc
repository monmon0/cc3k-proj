#include "Players.h"
#include "decorator.h"
#include <iostream>
#include <map>
#include "Potion.h"
#include "item.h"
#include <ctime>
#include <string>

Player::Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def): 
    Character(next, race, x, y, hp, atk, def) {
        if (race == 'v') max_hp = INT_MAX;
        else max_hp = hp;
}

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

void Player::move(std::string dir, AsciiArt * curr) {
    // no,so,ea,we,ne,nw,se,sw
    // new block 
    announcement = "";

    char pos_check = atPostion(curr, dir);

    if (pos_check == '.' || pos_check == '#' || pos_check == '\\' || pos_check == '+' || pos_check == 'G') {
        x += new_block_x;
        y += new_block_y;
        if (pos_check == 'G') {
            // check for type of gold
            Item * gold = Item::getItem(y + new_block_y, x + new_block_x);
            // gold->applyEffect(this);
        }
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

char Player::atPostion(AsciiArt * d, std::string dir) {
    new_block_x = 0;
    new_block_y = 0;

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
    } else if (dir == "sw") {
        new_block_x--;
        new_block_y++;
    }

    return d->charAt(y + new_block_y, x + new_block_x, 1);
}

bool Player::attack(AsciiArt * d, std::string dir) {
    // if (d->charAt())
    srand(time(0));
    int chance = rand() % hitbyH;
    char curr = atPostion(d, dir);

    if (!chance && (curr == 'H' || curr == 'W' || curr == 'E' || curr == 'L'
        || curr == 'O' || curr == 'M' || curr == 'D')) {

        if (race == 'v') {
            if (curr == 'W') hp -= 5;
            else hp += 5;
        }
        if (curr == 'M') 
        return 1;
    } 
    else move(dir, d);
    return 0;
};

void Player::takePotion(AsciiArt * m, std::string dir) {
    // magnified effects x 1.5
    char pos_check = atPostion(m, dir);

    if (pos_check == 'P') {
        Item * p = Item::getItem(y + new_block_y, x + new_block_x);
        p->applyEffect(this);
        announcement = p->getAnnouncement();
    } else {
        announcement = "PC didn't find any potions in this direction. ";
    }
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
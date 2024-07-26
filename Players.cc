#include "Players.h"
#include "decorator.h"
#include <iostream>
#include "Potion.h"
#include "item.h"
#include <ctime>
#include <climits>
#include "itemFactory.h"
#include <string>


Player::Player(AsciiArt *next, char race, int x, int y, int hp, int atk, int def, int location): 
    Character(next, race, x, y, hp, atk, def), location{location} {
        inventoryNum = 0;
        if (race == 'v') max_hp = INT_MAX;
        else max_hp = hp;
}

void Player::move(std::string dir, AsciiArt * curr) {
    announcement = "";

    char pos_check = atPostion(curr, dir);

    if (pos_check == '.' || pos_check == '#' || pos_check == '\\' || pos_check == '+' || pos_check == 'G') {
        x += new_block_x;
        y += new_block_y;

        if (pos_check == 'G') {
            // check for type of gold
            Item * gold = Item::getItem(x, y);
            gold->applyEffect(this);
            if (gold->collectable()) announcement = "PC collects a gold coin and moves " + dirMap[dir] + ". ";
            announcement += "PC moves " + dirMap[dir] + ". ";
        }
        else announcement += "PC moves " + dirMap[dir] + ". ";

        // troll gains 5 hp every turn
        if (race == 't') {
            if (hp + 5 <= max_hp) hp += 5;
            else hp = max_hp;
        }
         // check for staircase
        if (pos_check == '\\') {
            // notify to level up!
            levelUp = true;
        }
    } else announcement = "PC tried to move but couldn't. ";
}

char Player::charAt(int row, int col) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col);
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

    return d->charAt(y + new_block_y, x + new_block_x);
}

bool Player::attack(AsciiArt * d, std::string dir) {
    announcement = "";
    srand(time(0));
    char curr = atPostion(d, dir);

    if (hitbyH == false) {
        if (curr == 'H' || curr == 'W' || curr == 'E' || 
            curr == 'L' || curr == 'O' || curr == 'M' || curr == 'D') {
            if (race == 'v') {
                if (curr == 'W') hp -= 5;
                else hp += 5;
            }
            if (curr == 'M') hitMerchant = true;
            return true;
        } 
        move(dir, d);
    } else { 
        announcement = "PC missed the attack due to Halfing Poison. ";
        // reset if get hit by halfing
        move(dir, d);
        hitbyH = false;
    } 

    return false;
};

void Player::takePotion(AsciiArt * m, std::string dir, bool hasInventory) {
    char pos_check = atPostion(m, dir);

    if (pos_check == 'P') {
        Item * p = Item::getItem(x + new_block_x, y + new_block_y);
        inventoryNum++;
        if (hasInventory && inventoryNum < 10) {
            std::string name = p->getName();
            Item * potion;
        if (name == "RH") {
            potion = ItemFactory::createItem(ItemFactory::Type::POTION_RH, m, -1, -1);
        } else if (name == "BA") { 
            potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BA, m, -1, -1);

        } else if (name == "BD") { 
            potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BD, m, -1, -1);

        } else if (name == "PH") { 
            potion = ItemFactory::createItem(ItemFactory::Type::POTION_PH, m, -1, -1);

        } else if (name == "WA") { 
            potion = ItemFactory::createItem(ItemFactory::Type::POTION_WA, m,-1, -1);

        } else { 
            potion = ItemFactory::createItem(ItemFactory::Type::POTION_WD, m,-1, -1);

        }
            inventory.emplace_back(potion);
            p->changeActive();
        } else if (!hasInventory) {
            p->applyEffect(this);
            announcement = p->getAnnouncement();
        } 
    } else {
        announcement = "PC didn't find any potions in this direction. ";
    }
}

void Player::drinkPotion(int pos) {
    if (pos > (inventoryNum - 1)) {
        return;
    }
    inventory[pos]->applyEffect(this);

    inventory[pos]->nextChar() = nullptr;
    inventory.erase(inventory.begin() + pos);
    announcement = "PC uses potion in inventory. ";

    inventoryNum--;
};

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
    for (Potion * p: potions) {
        p->undoEffect(this);
    }
    potions.clear();
}

char Player::getRace() {return race;}
void Player::addGold(int amt) {gold += amt;}
void Player::getHitbyHalfing() {hitbyH = true;}
bool Player::isFriend() { return hitMerchant == false; }
void Player::setAtk(int x) {atk = x;}
int Player::getLocation() { return location; }
void Player::changeAtk(double x) { atk += x;}
void Player::changeDef(double x) { def += x;}
int Player::getMaxHP() {return max_hp;}
int Player::getGold() const { return gold;}                

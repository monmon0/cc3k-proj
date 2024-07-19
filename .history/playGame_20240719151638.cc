#include "playGame.h"
#include <iostream>
#include <random>
using namespace std;

PlayGame::PlayGame(Dungeon *d) : d{d} {}

void PlayGame::play() {
    spawnPotions();
    // spawnTreasure();
    spawnEnemies();
}

void PlayGame::end() {
    destroyPotions();
    // destroyEnemies();
    // destroyTreasure();
}


void PlayGame::levelUp() {
    // delete all decorator until player

    destroyPotions();
    // destroyEnemies();
    // destroyTreasure();
    d->levelUp();
    // spawnTreasure();
    // spawnEnemies();

    // NOTE: when enemies or potions its used, 
    // in getChar(), using a boolean to track,
    // if it false, return next
}

void PlayGame::destroyPotions() {
    // delete all potions until player
    for (int i = 0; i < 10; i++) {
        d->picture() = first_P->nextChar();
    }
    first_P->nextChar() = nullptr;
}

void PlayGame::spawnPotions() {
    
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 6;
        string name = names[idx];

        RandomPos random{d};
        random.setPos();
        int r1 = random.getX();
        int r2 = random.getY();

        if (name == "RH") {
            Potion * potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BA") {
            Potion * potion  = new BA(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BD") {
            Potion * potion  = new BD(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "PH") {
            Potion * potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "WA") {
            Potion * potion = potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else {
            Potion * potion = new WD(d->picture(), r1, r2, name);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        }
    }
}

void PlayGame::spawnEnemies() {
    vector<char> characters = {'H', 'W', 'E', 'O', 'M', 'L'};

    for (int i = 0; i < 10; i++) {
        std::random_device rd;   // Seed generator
    std::mt19937 gen(rd());  // Mersenne Twister RNG

    // Define the range
    std::uniform_int_distribution<> dis(0, 5);

    // Generate a random number in the range [0, 5]
    int random_number = dis(gen);
        int idx = rand() % 6;
        char name = characters[idx];

        RandomPos random{d};
        random.setPos();

        if (name == 'H') {
            Human *hp = new Human(d->picture(), random.getX(), random.getY()); 
            d->picture() = hp;  
        } else if (name == 'W') {
            Dwarf *wp = new Dwarf(d->picture(), random.getX(), random.getY()); 
            d->picture() = wp; 
        } else if (name == 'E') {
            Elf *ep = new Elf(d->picture(), random.getX(), random.getY()); 
            d->picture() = ep; 
        } else if (name == 'O') {
            Orc *op = new Orc(d->picture(), random.getX(), random.getY()); 
            d->picture() = op; 
        } else if (name == 'M') {
            Merchant *mp = new Merchant(d->picture(), random.getX(), random.getY()); 
            d->picture() = mp; 
        } else if (name == 'L') {
            Halfling *lp = new Halfling(d->picture(), random.getX(), random.getY()); 
            d->picture() = lp; 
        } else {
            Dragon *dp = new Dragon(d->picture(), random.getX(), random.getY()); 
            d->picture() = dp; 
        }
    }
}



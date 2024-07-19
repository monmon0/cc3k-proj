#include "playGame.h"
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

    // std::random_device rd;
    // std::mt19937 g(rd());

    for (int i = 0; i < 10; i++) {
        // std::shuffle(characters.begin(), characters.end(), g);
        RandomPos random{d};

        // if (characters[0] == 'H') {
        //     Human *hp = new Human(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = hp;  
        // } else if (characters[0] == 'W') {
        //     Dwarf *wp = new Dwarf(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = wp; 
        // } else if (characters[0] == 'E') {
        //     Elf *ep = new Elf(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = ep; 
        // } else if (characters[0] == 'O') {
        //     Orc *op = new Orc(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = op; 
        // } else if (characters[0] == 'M') {
        //     Merchant *mp = new Merchant(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = mp; 
        // } else if (characters[0] == 'L') {
        //     Halfling *lp = new Halfling(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = lp; 
        // } else if (characters[0] == 'D') {
        //     Dragon *dp = new Dragon(d->picture(), random.getX(), random.getY()); 
        //     d->picture() = dp; 
        // }

        Human *hp = new Human(d->picture(), random.getX(), random.getY()); 
        d->picture() = hp; 
    }
}



#include "playGame.h"
#include <string>
using namespace std;

PlayGame::PlayGame(Dungeon *d) : d{d} {}

void PlayGame::play() {    
    uint32_t seed = getpid(); 
    PRNG prng(seed); 

    spawnPotions(prng);
    // spawnTreasure();
    spawnEnemies(prng);
}

void PlayGame::restart(Player * p) {
    levelUp(p);
    std::cout << "Let's restart, choose your race again!" << std::endl;
    std::string command;
    std::cin >> command;
    // command and restart stat
    if (command == "s") p->restartSettings('s', 125, 25, 15);
    else if (command == "d") p->restartSettings('d', 150, 25, 15);
    else if (command == "v") p->restartSettings('v', 50, 25, 5);
    else if (command == "t") p->restartSettings('t', 120, 25, 15);
    else if (command == "g") p->restartSettings( 'g', 110, 25, 15);
}

void PlayGame::levelUp(Player * p) {
    // delete all decorator until player

    // destroyEnemies();
    // destroyTreasure();
    destroyPotions();

    d->levelUp();
    p->toggleLevel();
    d->picture() = p;
    play();

    // NOTE: when enemies or potions its used, 
    // in getChar(), using a boolean to track,
    // if it false, return next
}

bool PlayGame::checkCoord(int x, int y) {
    return (d->picture()->charAt(y, x, 1) == '.'); 
}

void PlayGame::destroyPotions() {
    // delete all potions until player
    for (int i = 0; i < 10; i++) {
        d->picture() = first_P->nextChar();
    }
    first_P->nextChar() = nullptr;
}

void PlayGame::spawnPotions(PRNG prng) {  
    uint32_t seed = getpid(); 
    PRNG prng(seed); 

    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 6;
        string name = names[idx];

        int r1 = rand() % 79;
        int r2 = rand() % 25;

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
        std::cout << name << std::endl;
    }
}

void PlayGame::spawnEnemies(PRNG prng) {    
    vector<char> characters = {'H', 'W', 'E', 'O', 'M', 'L'};

    for (int i = 0; i < 20; i++) {
        int idx = prng() % 6; 
        cout << idx << endl; 
        char name = characters[idx];

        int r1 = prng() % 79;
        int r2 = prng() % 25; 

        if (checkCoord(r1, r2)) {
            if (name == 'H') {
                Enemy *hp = new Human(d->picture(), r1, r2); 
                d->picture() = hp;  
                eVec.emplace_back(hp);
            } else if (name == 'W') {
                Enemy *wp = new Dwarf(d->picture(), r1, r2); 
                d->picture() = wp; 
                eVec.emplace_back(wp);
            } else if (name == 'E') {
                Enemy *ep = new Elf(d->picture(),r1, r2); 
                d->picture() = ep; 
                eVec.emplace_back(ep);
            } else if (name == 'O') {
                Enemy *op = new Orc(d->picture(), r1, r2); 
                d->picture() = op; 
                eVec.emplace_back(op);
            } else if (name == 'M') {
                Enemy *mp = new Merchant(d->picture(), r1, r2); 
                d->picture() = mp; 
                eVec.emplace_back(mp);
            } else if (name == 'L') {
                Enemy *lp = new Halfling(d->picture(), r1, r2); 
                d->picture() = lp; 
                eVec.emplace_back(lp);
            } else {
                Enemy *dp = new Dragon(d->picture(), r1, r2); 
                d->picture() = dp; 
                eVec.emplace_back(dp);
            }
        } else { i--; }
    }
}

void moveEnemies() {
    // for (auto e : eVec) {
    //     e->move(); 
    // }
}



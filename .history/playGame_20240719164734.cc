#include "playGame.h"
#include <string>
using namespace std;

PlayGame::PlayGame(Dungeon *d) : d{d} {}

void PlayGame::play() {

    spawnPotions();
    // spawnTreasure();
    spawnEnemies();
}

void PlayGame::restart(Player * p) {
    levelUp(p);
    std::cout << "Let's restart, choose your race again!" << std::endl;
    std::string command;
    std::cin >> command;
    // command and restart stat
    if (command == "s") p->restartSettings('s', 125, 25, 15);
    else if (command == "d") p->restartSettings('d', 150, 25, 15);
    else if (command == "v") p->restartSettings( 'v', 50, 25, 5);
    else if (command == "t") p->restartSettings('t', 120, 25, 15);
    else if (command == "g") p->restartSettings( 'g', 110, 25, 15);


}

void PlayGame::levelUp(Player * p) {
    // delete all decorator until player

    destroyPotions();
    // destroyEnemies();
    // destroyTreasure();
    // spawnTreasure();
    // spawnEnemies();
    d->levelUp();
    p->toggleLevel();
    d->picture() = p;
    play();

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

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int idx = rand() % 6;
        cout << idx << endl; 
        char name = characters[idx];

        RandomPos random{d};
        random.setPos();


        if (name == 'H') {
            Human *hp = new Human(d->picture(), r1, r2); 
            d->picture() = hp;  
        } else if (name == 'W') {
            Dwarf *wp = new Dwarf(d->picture(), r1, r2); 
            d->picture() = wp; 
        } else if (name == 'E') {
            Elf *ep = new Elf(d->picture(),r1, r2); 
            d->picture() = ep; 
        } else if (name == 'O') {
            Orc *op = new Orc(d->picture(), r1, r2); 
            d->picture() = op; 
        } else if (name == 'M') {
            Merchant *mp = new Merchant(d->picture(), r1, r2); 
            d->picture() = mp; 
        } else if (name == 'L') {
            Halfling *lp = new Halfling(d->picture(), r1, r2); 
            d->picture() = lp; 
        } else {
            Dragon *dp = new Dragon(d->picture(), r1, r2); 
            d->picture() = dp; 
        }
    }
}



#include "playGame.h"
#include <string>
#include <ctime>
using namespace std;

PlayGame::PlayGame(Dungeon *d, Player *p = nullptr) : d{d}, p{p} {}

void PlayGame::play() {    

    int seed = time(0);
    spawnStaircase(seed); 
    spawnTreasure(seed);
    spawnPotions(seed);
    spawnEnemies(seed);
}

void PlayGame::restart(Player * p) {
    levelUp(p);
    d->resetLevel();
    std::cout << "Let's restart, choose your race again!" << std::endl;
    std::string command;
    std::cin >> command;
    // WRITE NEW RESTART

    // if      (command == "s") p->restartSettings('s', 125, 25, 15);
    // else if (command == "d") p->restartSettings('d', 150, 25, 15);
    // else if (command == "v") p->restartSettings('v', 50, 25, 5);
    // else if (command == "t") p->restartSettings('t', 120, 25, 15);
    // else if (command == "g") p->restartSettings('g', 110, 25, 15);
}

void PlayGame::levelUp(Player * p) {
    // delete all decorator until player

    destroyEnemies();
    destroyPotions();
    destroyTreasure();
    
    d->levelUp();

    uint32_t seed = getpid();
    CheckCoord c{d, seed}; 
    c.setPos(); 
    int r1 = c.getX(), r2 = c.getY();

    p->nextLevel(r1, r2);
    d->picture() = p;

    play();
}

void PlayGame::attachPC(Player *pc) {
    p = pc; 
}

void PlayGame::spawnStaircase(uint32_t seed) {
    CheckCoord c{d, seed}; 
    c.setPos(); 
    int r1 = c.getX(), r2 = c.getY();
    Staircase *sp = new Staircase(d->picture(), r1, r2); 
    d->picture() = sp; 
}

void PlayGame::destroyPotions() {
    // delete all potions until player
    for (int i = 0; i < 10; i++) d->picture() = first_P->nextChar();
    first_P->nextChar() = nullptr;
    d->picture() = first_T;
}

void PlayGame::destroyTreasure() {
    // delete all treasure until player
    for (int i = 0; i < 10; i++) d->picture() = first_T->nextChar();
    first_T->nextChar() = nullptr;
    
}

void PlayGame::destroyEnemies() {
    // delete all potions until player
    for (int i = 0; i < 20; i++) d->picture() = first_E->nextChar();
    eVec.clear();
    d->picture() = first_P;
}

void PlayGame::spawnPotions(uint32_t seed) {  
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 79;
        string name = names[idx % 6];


        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
        // int r2 = d->getLevel(), r1 = i + 4;
    
        if (name == "RH") {
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_RH, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BA") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BA, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BD") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BD, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "PH") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_PH, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "WA") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WA, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WD, d->picture(), r2, r1);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        }
    }
}

void PlayGame::spawnTreasure(uint32_t seed) {
    for (int i = 0; i < 10; i++) {
        int num = rand() % 8;
        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
        
        Item *treasure;
        if (num < 5) {  // spawn normal gold
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_NORMAL, d->picture(), r2, r1);
            d->picture() = treasure;
            if (i == 9) {
                first_T = treasure;
            }
        } else if (num < 6) {   // spawn dragon hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_DRAGON, d->picture(), r2, r1);
            d->picture() = treasure;
            if (i == 9) {
                first_T = treasure;
            }
        } else {    // spawn small hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_SMALL, d->picture(), r2, r1);
            d->picture() = treasure;
            if (i == 9) {
                first_T = treasure;
            }
        }
    }
}

void PlayGame::spawnEnemies(uint32_t seed) {    
    vector<char> characters = {'H', 'W', 'E', 'O', 'M', 'L'};

    for (int i = 0; i < 20; i++) {
        int idx = rand() % 6;
        char name = characters[idx]; 

        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
        // int r2 = 4 + d->getLevel(), r1 = i + 4;

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
    } 
    first_E = eVec.back();
}

void PlayGame::attackOrMove() {
    for (auto e : eVec) {
        e->atkOrMv(p, d); 
    }
}

void PlayGame::end() {
    // score game
}


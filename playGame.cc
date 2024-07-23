#include "playGame.h"
#include <string>
#include <ctime>
#include "asciitext.h"
using namespace std;

 
PlayGame::PlayGame(Dungeon *d) : d{d} {
     // --------------- START GAME ------------------------- //
    std::cout << WELCOME << '\n'
              << "         WELCOME to SYLVIA, EASON & MONICA CC3k    "              << std::endl
    << "Please start by entering one of the following command to choose your hero:" << std::endl
    << "       (s): Shade, (d): Drow, (v): Vampire, (g):Goblin, (t):Troll"          << std::endl;
    std::cout << "Your command: ";
}

void PlayGame::play() {
    int seed = time(0);
    spawnStaircase(seed); 
    spawnPotions(seed);
    spawnTreasure(seed);
    spawnEnemies(seed);
}

void PlayGame::restart() {
    levelUp();
    d->resetLevel();  
    d->clearAction();
    std::cout << RESTART << std::endl;
    std::cout << "RESTART by choosing your race again: ";
}

void PlayGame::levelUp() {
    // delete all decorator until player
    destroyEnemies();
    destroyTreasure();
    destroyPotions();

    d->levelUp();
    d->clearAction();
    d->setAction("Next Floor Unlocked! Good job! ");

    uint32_t seed = getpid();
    CheckCoord c{d, seed}; 
    c.setPos(); 
    int r1 = c.getX(), r2 = c.getY();

    p->nextLevel(r1, r2);
    d->picture() = p;

    play();
}

void PlayGame::spawnStaircase(uint32_t seed) { 
    CheckCoord c{d, seed}; 
    while (true) {
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
        if (p->getLocation() != c.getChamber()) {
            Staircase *sp = new Staircase(d->picture(), r1, r2); 
            d->picture() = sp; 
            break; 
        }
    }
}

void PlayGame::destroyPotions() {
    // delete all potions until player
    for (int i = 0; i < 10; i++) d->picture() = first_P->nextChar();
    first_P->nextChar() = nullptr;
    d->picture() = p;
}

void PlayGame::destroyTreasure() {
    // delete all treasure until player
    for (int i = 0; i < 10; i++) d->picture() = first_T->nextChar();
    first_T->nextChar() = first_P;
    
}

void PlayGame::deadOrQuit() {
    p->setAtk(0);
    std::cout << WOMP_WOMP << std::endl;
    std::cout << "             WOULD YOU LIKE TO PLAY AGAIN?" << std::endl;
    std::cout << "                 (enter -r to restart)"     << std::endl;
}

void PlayGame::destroyEnemies() {
    // delete all potions until player
    for (int i = 0; i < eVec.size(); i++) d->picture() = first_E->nextChar();
    eVec.clear();
    d->picture() = first_T;
}

void PlayGame::spawnPotions(uint32_t seed) {  
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 6;
        string name = names[idx];


        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
    
        if (name == "RH") {
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_RH, d->picture(), r1, r2);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BA") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BA, d->picture(), r1, r2);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "BD") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BD, d->picture(), r1, r2);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "PH") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_PH, d->picture(), r1, r2);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else if (name == "WA") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WA, d->picture(), r1, r2);
            d->picture() = potion;
            if (i == 9) first_P = potion;
        } else { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WD, d->picture(), r1, r2);
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
        if (num < 5) {          // spawn normal gold
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_NORMAL, d->picture(), r1, r2);
            d->picture() = treasure;
            if (i == 9) {
                first_T = treasure;
            }
        } else if (num < 6) {   // spawn dragon hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_DRAGON, d->picture(), r1, r2);
            d->picture() = treasure;
            
            std::vector<int> arr = {-1, 0, 1}; 
            int x, y; 
            
            while (true) {
                int idx = rand() % 3;
                int dx = arr[idx]; 
                idx = rand() % 3;
                int dy = arr[idx]; 

                x = treasure->getX() + dx;
                y = treasure->getY() + dy; 

                if (d->picture()->charAt(y, x, 1) == '.') {
                    break; 
                } 
            } 

            Enemy *dragon = new Dragon(d->picture(), x, y, static_cast<Dragon_Hoard*>(treasure));
            eVec.emplace_back(dragon);
            d->picture() = dragon;
            if (i == 9) {
                first_T = treasure;
            }
        } else {    // spawn small hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_SMALL, d->picture(), r1, r2);
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
        } else {
            Enemy *lp = new Halfling(d->picture(), r1, r2); 
            d->picture() = lp; 
            eVec.emplace_back(lp);
        }
    } 
    first_E = eVec.back(); 
}

void PlayGame::fPressed() {
    for (auto e : eVec) {
        e->fPressed = !e->fPressed; 
    }
}

void PlayGame::attackOrMove() {
    for (auto e : eVec) {
        e->atkOrMv(p, d); 
        d->setAction(e->getAnnouncement());
    }
}

void PlayGame::defeatEnemies(int x, int y, std::string dir) {
    if (dir == "no") {
        y--; 
    } else if (dir == "ne") {
        x++; 
        y--; 
    } else if (dir == "ea") {
        x++; 
    } else if (dir == "se") {
        x++; 
        y++; 
    } else if (dir == "so") { 
        y++; 
    } else if (dir == "sw") {
        x--; 
        y++; 
    } else if (dir == "we") {
        x--; 
    } else if (dir == "nw") {
        x--; 
        y--; 
    } 
    for (auto e : eVec) {
        if (e->getX() == x && e->getY() == y) {
            int damage = ceil((100/(100 + e->getDef())) * p->getAtk()); 
            e->loseHP(damage); 
            d->setAction("PC deals " +
                            std::to_string(damage) + 
                            " damage to " + std::string(1, e->getRace()) + ". ");
            if (e->isDead()) {
                p->addGold( p->getRace() == 'g' ? 10 : 5 );
                d->setAction(std::string(1, e->getRace()) + " is slained. ");
            }
        }
    }
}

void PlayGame::end() {
    // score game
    int pts = p->getGold();
    if (p->getRace() == 's') pts *= 2;
    std::cout << VICTORY << '\n';
    std::cout << "CONGRATULATIONS! YOU HAVE ESCAPED THE DUNGEON!    " << std::endl;
    std::cout << "        YOUR SCORE: " << pts << " points"           << std::endl;
    std::cout << "    WOULD YOU LIKE TO PLAY AGAIN?"                  << std::endl;
    std::cout << " (enter -r to restart, any key to esc)"             << std::endl;
}

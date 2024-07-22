#include "playGame.h"
#include <string>
#include <ctime>
using namespace std;

 
PlayGame::PlayGame(Dungeon *d) : d{d} {
     // --------------- START GAME ------------------------- //
    std::cout << R"(
                      _                            _               
        __      _____| | ___ ___  _ __ ___   ___  | |_ ___         
        \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \        
         \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |       
  ____ ___\_/\_/_\___|_|\___\___/|_| |_| |_|\___|  \__\___/        
 / ___/ ___|___ /| |/ /   __| |_   _ _ __   __ _  ___  ___  _ __   
| |  | |     |_ \| ' /   / _` | | | | '_ \ / _` |/ _ \/ _ \| '_ \  
| |__| |___ ___) | . \  | (_| | |_| | | | | (_| |  __/ (_) | | | | 
 \____\____|____/|_|\_\  \__,_|\__,_|_| |_|\__, |\___|\___/|_| |_| 
                                           |___/                        
    )" << '\n'
              << "         WELCOME to SYLVIA, EASON & MONICA CC3k    " << std::endl
    << "Please start by entering one of the following command to choose your hero:" << std::endl
    << "       (s): Shade, (d): Drow, (v): Vampire, (g):Goblin, (t):Troll"          << std::endl;
    std::cout << "Your command: ";
}

void PlayGame::play() {    
    int seed = time(0);
    spawnStaircase(seed); 
    spawnTreasure(seed);
    spawnPotions(seed);
    spawnEnemies(seed);
}

void PlayGame::restart() {
    levelUp();
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

void PlayGame::levelUp() {
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

void PlayGame::attachPC(Player *pc) {p = pc;}

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
    for (int i = 0; i < eVec.size(); i++) d->picture() = first_E->nextChar();
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
        if (num < 1) {          // spawn normal gold
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_NORMAL, d->picture(), r2, r1);
            d->picture() = treasure;
            if (i == 9) {
                first_T = treasure;
            }
        } else if (num < 9) {   // spawn dragon hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_DRAGON, d->picture(), r2, r1);
            // int x_dir = rand() % 2;
            // int y_dir = rand() % 2;
            // Enemy *dragon = new Dragon(d->picture(), r2 + 1, r1 + 2); 
            // eVec.emplace_back(dragon);
            // d->picture() = dragon;
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
        } else {
            Enemy *lp = new Halfling(d->picture(), r1, r2); 
            d->picture() = lp; 
            eVec.emplace_back(lp);
        }
    } 
    first_E = eVec.back();
}

void PlayGame::attackOrMove() {
    for (auto e : eVec) {
        e->atkOrMv(p, d); 
        d->setAction(e->getAnnouncement());
    }
}

void PlayGame::defeatEnemies(int x, int y, Player *p, std::string dir) {
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
            double damage = ceil((100/(100 + e->getDef())) * p->getAtk()); 
            e->loseHP(damage); 
            if (e->isDead()) p->addGold(5); 
        }
    }
}

void PlayGame::end() {
    // score game
    int pts = p->getGold();
    if (p->getRace() == 's') pts *= 2;
    std::cout << R"(
__     _____ ____ _____ ___  ______   __  _   _ 
\ \   / /_ _/ ___|_   _/ _ \|  _ \ \ / / | | | |
 \ \ / / | | |     | || | | | |_) \ V /  | | | |
  \ V /  | | |___  | || |_| |  _ < | |   |_| |_|
   \_/  |___\____| |_| \___/|_| \_\|_|   (_) (_)        
    )" << '\n';
    std::cout << "   CONGRATULATIONS! YOU HAVE ESCAPED THE DUNGEON!    " << std::endl;
                std::cout << "        YOUR SCORE: " << pts << " points"             << std::endl;
                std::cout << "    WOULD YOU LIKE TO PLAY AGAIN?" << std::endl;
                std::cout << " (enter -r to restart, any key to esc)"         << std::endl;
}


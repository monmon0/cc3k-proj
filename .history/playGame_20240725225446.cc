#include "playGame.h"
#include <string>
#include <ctime>
#include "asciitext.h"
using namespace std;

class Blank; 

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

void PlayGame::play(Blank *map) {
    spawn(map);
}

void PlayGame::levelUp(bool hasCommand, Blank *map) {
    // delete all decorator until player
    int r1, r2;
    if (hasCommand) {
        int pos = map->getMap().find("@");
        r1 = pos % 79;
        r2 = pos / 79;
    } else {
        uint32_t seed = getpid();
        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX();
        int r2 = c.getY();
    }

    p->nextLevel(r1, r2);
    sc->nextChar() = nullptr;
    
    delete d->picture();
    d->picture() = p;

    d->levelUp();
    d->clearAction();
    d->setAction("Next Floor Unlocked! Good job! ");

    eVec.clear();
    eMap.clear();
    if (hasCommand) {
        play(map);
    } else {
        play();
    }
}

void PlayGame::restart() {
    // levelUp();
    AsciiArt * curr = p->nextChar();
    p->nextChar() = nullptr;
    delete d->picture();

    d->picture() = curr;
    p = nullptr;
    sc = nullptr;
    eVec.clear();
    eMap.clear();
    d->resetLevel();  
    d->clearAction();
    std::cout << RESTART << std::endl;
    std::cout << "RESTART by choosing your race again: ";
}

void PlayGame::spawnStaircase(uint32_t seed) { 
    CheckCoord c{d, seed}; 
    while (true) {
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();
        if (p->getLocation() != c.getChamber()) {
            Staircase *sp = new Staircase(d->picture(), r1, r2); 
            sc = sp;
            d->picture() = sp; 
            break; 
        }
    }
}

void PlayGame::deadOrQuit() {
    p->setAtk(0);
    std::cout << WOMP_WOMP << std::endl;
    std::cout << "             WOULD YOU LIKE TO PLAY AGAIN?" << std::endl;
    std::cout << "                 (enter r to restart)"     << std::endl;
}

void PlayGame::spawn(Blank *map) { 
    int idx = map->getMap().find('\\');
    Staircase *sp = new Staircase(d->picture(), idx % 79, idx / 79);
    sc = sp;
    d->picture() = sp; 
    for (int row = 0; row < 25; row++) {
        for (int col = 0; col < 79; col++) {
            char letter = map->charAt(row, col);

            if (letter == '.') { 
                continue;
            } else if (letter == '0') {
                Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_RH, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '1') {
                Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BA, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '2') {
                Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BD, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '3') {
                Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_PH, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '4') {
                Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_WA, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '5') {
                Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WD, d->picture(), col, row);
                d->picture() = potion;
            } else if (letter == '6') {
                Item *treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_NORMAL, d->picture(), col, row);
                d->picture() = treasure;
            } else if (letter == '7') {
                Item *treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_SMALL, d->picture(), col, row);
                d->picture() = treasure;
            } else if (letter == '8') {
                Item *treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_MERCHANT, d->picture(), col, row);
                d->picture() = treasure;
            } else if (letter == '9') {
                Item *treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_DRAGON, d->picture(), col, row);
                d->picture() = treasure;

                Enemy *dp; 
                if (map->charAt(row - 1, col - 1) == 'D') dp = new Dragon(d->picture(), col - 1, row - 1, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row - 1, col) == 'D') dp = new Dragon(d->picture(), col, row - 1, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row, col - 1) == 'D') dp = new Dragon(d->picture(), col - 1, row, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row + 1, col + 1) == 'D') dp = new Dragon(d->picture(), col + 1, row + 1, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row + 1, col) == 'D') dp = new Dragon(d->picture(), col, row + 1, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row, col + 1) == 'D') dp = new Dragon(d->picture(), col + 1, row, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row + 1, col - 1) == 'D') dp = new Dragon(d->picture(), col - 1, row + 1, static_cast<Dragon_Hoard*>(treasure));
                else if (map->charAt(row - 1, col + 1) == 'D') dp = new Dragon(d->picture(), col + 1, row - 1, static_cast<Dragon_Hoard*>(treasure));
                
                d->picture() = dp;
                eVec.emplace_back(dp);
            } else if (letter == 'H') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::HUMAN, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            } else if (letter == 'W') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::DWARF, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            } else if (letter == 'E') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::ELF, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            } else if (letter == 'O') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::ORC, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            } else if (letter == 'M') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::MERCHANT, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            } else if (letter == 'L') {
                Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::HALFLING, d->picture(), col, row);
                d->picture() = e;
                eVec.emplace_back(e);
            }

            int counter = 0; 
            for (auto e : eVec) {
                eMap[counter] = make_pair(e->getX(), e->getY());
                counter++;  
            }

        }
    }
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

        } else if (name == "BA") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BA, d->picture(), r1, r2);
            d->picture() = potion;

        } else if (name == "BD") { 
            Item * potion  = ItemFactory::createItem(ItemFactory::Type::POTION_BD, d->picture(), r1, r2);
            d->picture() = potion;

        } else if (name == "PH") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_PH, d->picture(), r1, r2);
            d->picture() = potion;

        } else if (name == "WA") { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WA, d->picture(), r1, r2);
            d->picture() = potion;

        } else { 
            Item * potion = ItemFactory::createItem(ItemFactory::Type::POTION_WD, d->picture(), r1, r2);
            d->picture() = potion;

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

                if (d->picture()->charAt(y, x) == '.') {
                    break; 
                } 
            } 

            Enemy *dragon = new Dragon(d->picture(), x, y, static_cast<Dragon_Hoard*>(treasure));
            eVec.emplace_back(dragon);
            d->picture() = dragon;
    
        } else {    // spawn small hoard
            treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_SMALL, d->picture(), r1, r2);
            d->picture() = treasure;
            
        }
    }
}

void PlayGame::spawnEnemies(uint32_t seed) { 
    vector<char> characters = {'H', 'H', 'H', 'H', 'W', 'W', 'W', 'E', 'E', 'O', 'O', 'M', 'M', 'L', 'L', 'L', 'L', 'L'};
    for (int i = 0; i < 20; i++) {
        int idx = rand() % 18;
        char name = characters[idx]; 

        CheckCoord c{d, seed}; 
        c.setPos(); 
        int r1 = c.getX(), r2 = c.getY();

        if (name == 'H') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::HUMAN, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        } else if (name == 'W') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::DWARF, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        } else if (name == 'E') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::ELF, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        } else if (name == 'O') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::ORC, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        } else if (name == 'M') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::MERCHANT, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        } else if (name == 'L') {
            Enemy *e = EnemyFactory::createEnemy(EnemyFactory::Type::HALFLING, d->picture(), r1, r2);
            d->picture() = e;
            eVec.emplace_back(e);
        }
    } 

    int counter = 0; 
    for (auto e : eVec) {
        eMap[counter] = make_pair(e->getX(), e->getY());
        counter++;  
    }
}

void PlayGame::fPressed() {
    for (auto e : eVec) {
        e->fPressed = !e->fPressed; 
    }
}

void PlayGame::attackOrMove() {
    // Define the lambda function for custom comparison
    auto comparePairs = [](const std::pair<int, std::pair<int, int>>& a, const std::pair<int, std::pair<int, int>>& b) {
        if (a.second.second == b.second.second) { // Compare y-coordinates
            return a.second.first < b.second.first; // Compare x-coordinates if y-coordinates are the same
        }
        return a.second.second < b.second.second;
    };


    // Create a vector of pairs to sort because std::map can't be sorted directly
    std::vector<std::pair<int, std::pair<int, int>>> sortedMap(eMap.begin(), eMap.end());

    // Sort the vector using the custom comparator
    std::sort(sortedMap.begin(), sortedMap.end(), comparePairs);

    // Iterate over the sorted vector and perform the actions

    for (const auto& it : sortedMap) {
        int index = it.first;
        eVec[index]->atkOrMv(p, d);
        d->setAction(eVec[index]->getAnnouncement());
        eMap[index] = std::make_pair(eVec[index]->getX(), eVec[index]->getY());
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
                if (e->getRace() == 'H' || e->getRace() == 'M') {
                    Item *treasure = ItemFactory::createItem(ItemFactory::Type::GOLD_MERCHANT, d->picture(), e->getX(), e->getY());
                    d->picture() = treasure;
                } else {
                    if (e->getRace() != 'D') p->addGold( p->getRace() == 'g' ? 10 : 5 );
                }
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

void PlayGame::attachPC(Player * pc) {p = pc; }

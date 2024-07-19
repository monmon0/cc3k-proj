#include "playGame.h"
using namespace std;

PlayGame::PlayGame(Dungeon *d) : d{d} {}

void PlayGame::play() {
    spawnPotions();
    // spawnEnemies();
    // spawnTreasure();
}

void PlayGame::levelUp(int x, int y) {
    // delete all decorator until player
    // Decorator * curr = new Decorator(d->picture());
    // curr = curr->next;
    // d->picture() = curr;
}

void PlayGame::spawnPotions() {
   
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 5;
        string name = names[idx];

        RandomPos random{};
        random.setPos();
        int r1 = random.getX();
        int r2 = random.getY();

        if (name == "RH") {
            Potion * potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
        } else if (name == "BA") {
            Potion * potion  = new BA(d->picture(), r1, r2, name);
            d->picture() = potion;
        } else if (name == "BD") {
            Potion * potion  = new BD(d->picture(), r1, r2, name);
            d->picture() = potion;
        } else if (name == "PH") {
            Potion * potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
        } else if (name == "WA") {
            Potion * potion = potion = new RH(d->picture(), r1, r2, name);
            d->picture() = potion;
        } else {
            Potion * potion = new WD(d->picture(), r1, r2, name);
            d->picture() = potion;
        }
    }
}

void PlayGame::spawnEnemies() {
    // RandomPos random{curr}; 
    // vector<char> characters = {'H', 'W', 'E', 'O', 'M', 'L'};

    // std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(characters.begin(), characters.end(), g);

    // random.setPos();
    // if (characters[0] == 'H') {
        
    //     Human *hp = new Human(curr, random.getX(), random.getY()); 
    //     curr = hp;  
    // } else if (characters[0] == 'W') {
    //     Dwarf *wp = new Dwarf(curr, random.getX(), random.getY()); 
    //     curr = wp; 
    // } else if (characters[0] == 'E') {
    //     Elf *ep = new Elf(curr, random.getX(), random.getY()); 
    //     curr = ep; 
    // } else if (characters[0] == 'O') {
    //     Orc *op = new Orc(curr, random.getX(), random.getY()); 
    //     curr = op; 
    // } else if (characters[0] == 'M') {
    //     Merchant *mp = new Merchant(curr, random.getX(), random.getY()); 
    //     curr = mp; 
    // } else if (characters[0] == 'L') {
    //     Halfling *lp = new Halfling(curr, random.getX(), random.getY()); 
    //     curr = lp; 
    // } else if (characters[0] == 'D') {
    //     Dragon *dp = new Dragon(curr, random.getX(), random.getY()); 
    //     curr = dp; 
    // }
}



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

void PlayGame::end() {
    delete d;
}
void PlayGame::spawnPotions() {
   
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};

    for (int i = 0; i < 10; i++) {
        int idx = rand() % 5;
        string name = names[idx];

        // RandomPos random{curr};
        // random.setPos();
        int r1 = 79 % i;
        int r2 = 35 % i;

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
        
    //     Human *hp = new Human( d->picture() , random.getX(), random.getY()); 
    //     d->picture() = hp;  
    // } else if (characters[0] == 'W') {
    //     Dwarf *wp = new Dwarf( d->picture() , random.getX(), random.getY()); 
    //     d->picture()  = wp; 
    // } else if (characters[0] == 'E') {
    //     Elf *ep = new Elf( d->picture() , random.getX(), random.getY()); 
    //     d->picture()  = ep; 
    // } else if (characters[0] == 'O') {
    //     Orc *op = new Orc(curr, random.getX(), random.getY()); 
    //     d->picture()  = op; 
    // } else if (characters[0] == 'M') {
    //     Merchant *mp = new Merchant( d->picture() , random.getX(), random.getY()); 
    //     d->picture()  = mp; 
    // } else if (characters[0] == 'L') {
    //     Halfling *lp = new Halfling( d->picture() , random.getX(), random.getY()); 
    //     d->picture()  = lp; 
    // } else if (characters[0] == 'D') {
    //     Dragon *dp = new Dragon( d->picture() , random.getX(), random.getY()); 
    //     d->picture()  = dp; 
    // }
}



#include "playGame.h"
using namespace std;

PlayGame::PlayGame(AsciiArt *curr) : curr{curr} {}

void PlayGame::spawnPotions() {
    RandomPos random{curr};
    vector<string> names = {"RH", "BA", "BD", "PH", "WA", "WD"};
    for (int i = 0; i < 10; i++) {
        int idx = rand() % 5;
        string name = names[idx];
        random.setPos();
        Potion *potion;
        if (name == "RH") {
            potion = new RH(curr, random.getX(), random.getY(), name);
        } else if (name == "BA") {
            potion = new BA(curr, random.getX(), random.getY(), name);
        } else if (name == "BD") {
            potion = new BD(curr, random.getX(), random.getY(), name);
        } else if (name == "PH") {
            potion = new RH(curr, random.getX(), random.getY(), name);
        } else if (name == "WA") {
            potion = new RH(curr, random.getX(), random.getY(), name);
        } else {
            potion = new WD(curr, random.getX(), random.getY(), name);
        }
        curr = potion;
    }
}

void PlayGame::spawnEnemies() {
    RandomPos random{curr}; 
    vector<char> characters = {'H', 'W', 'E', 'O', 'M', 'L'};

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(characters.begin(), characters.end(), g);

    if (characters[0] == 'H') {
        Human *hp = new Human(curr, random.getX(), random.getY()); 
        curr = hp;  
    } else if (characters[0] == 'W') {
        Dwarf *wp = new Dwarf(curr, random.getX(), random.getY()); 
        curr = wp; 
    } else if (characters[0] == 'E') {
        Elf *ep = new Elf(curr, random.getX(), random.getY()); 
        curr = ep; 
    } else if (characters[0] == 'O') {
        Orc *op = new Orc(curr, random.getX(), random.getY()); 
        curr = op; 
    } else if (characters[0] == 'M') {
        Merchant *mp = new Merchant(curr, random.getX(), random.getY()); 
        curr = mp; 
    } else if (characters[0] == 'L') {
        Halfling *lp = new Halfling(curr, random.getX(), random.getY()); 
        curr = lp; 
    } else if (characters[0] == 'D') {
        Dragon *dp = new Dragon(curr, random.getX(), random.getY()); 
        curr = dp; 
    }
}



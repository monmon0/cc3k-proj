#include "elf.h"

Elf::Elf(AsciiArt *next, int xCoord, int yCoord)
    : Enemy(next, 'E', xCoord, yCoord, 140, 30, 10) {}

void Elf::atkOrMv(Player *pc, Dungeon *d) {
    if (isDead()) return; 
    announcement = "";
    std::vector<int> arr = {-1, 0, 1}; 

    int xDiff = abs(pc->getX() - x); 
    int yDiff = abs(pc->getY() - y);  

    if (xDiff <= 1 && yDiff <= 1) {
        int damage = ceil((100/(100 + pc->getDef())) * getAtk()); 
        if (rand() % 2 == 0) {
            pc->changeHP(-damage); 
            announcement = std::string(1, getRace())  // Convert char to std::string
                            + " deals " 
                            + std::to_string(damage)  // Convert int to std::string
                            + " damage to PC. ";
        } else {
            announcement = std::string(1, getRace()) + " missed. "; 
        } 
        
        if (pc->getRace() != 'd') {
            if (rand() % 2 == 0) {
                pc->changeHP(-damage); 
                announcement += "On the second try "
                                + std::string(1, getRace())  // Convert char to std::string
                                + " deals " 
                                + std::to_string(damage)  // Convert int to std::string
                                + " damage to PC. ";
            } else {
                announcement += "On the second try " + std::string(1, getRace()) + " missed. "; 
            }
        }
    } else { 
        for (int i : arr) {
            for (int j : arr) {
                if (d->picture()->charAt(y + i, x + j) == '.') {
                    while (!fPressed) {
                        int idx = std::rand() % 3;
                        int dx = arr[idx];
                        idx = std::rand() % 3;
                        int dy = arr[idx];

                        char pos_check = d->picture()->charAt(y + dy, x + dx);

                        if (pos_check == '.') {
                            x += dx;
                            y += dy;
                            return; // Exit the function once the position is updated
                        }
                    }
                } 
            }
        }
        return; 
    }
}

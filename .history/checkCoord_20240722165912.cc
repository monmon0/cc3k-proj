#include "checkCoord.h"

#include <iostream>
#include <random>

int CheckCoord::giveRandomInt(int i) {
    return prng() % i; 
}`

void CheckCoord::setPos() {		
    int new_x, new_y; 
    while (true) {
        int newChamber = prng() % 5;
        if (newChamber == 0) {
            new_x = 3 + prng() % 26;
            new_y = 3 + prng() % 3;
        } else if (newChamber == 1) {
            new_x = 4 + prng() % 21;
            new_y = 15 + prng() % 6;
        } else if (newChamber == 2) {
            new_x = 38 + prng() % 12;
            new_y = 10 + prng() % 3;
        } else if (newChamber == 3) {
            int inner_chamber = prng() % 3;
            if (inner_chamber == 0) {
                new_x = 39 + prng() % 4;
                new_y = 3 + prng() % 4;
            } else if (inner_chamber == 1) {
                new_x = 61 + prng() % 9;
                new_y = 19 + prng() % 8;
            } else if (inner_chamber == 2) {
                new_x = 61 + prng() % 15;
                new_y = 8 + prng() % 6;
            }
        } else if (newChamber == 4) {
            int inner_chamber = prng() % 2;
            if (inner_chamber == 0) {
                new_x = 36 + prng() % 39;
                new_y = 19 + prng() % 3;
            } else if (inner_chamber == 1) {
                new_x = 65 + prng() % 11;
                new_y = 16 + prng() % 3;
            }
        }
        
        if (curr->picture()->charAt(new_y, new_x, 1) == '.') {
            x = new_x;
            y = new_y;
            chamber = newChamber;
            break; // Exit the loop if a valid position is found
        } 
    };
}

void CheckCoord::setPosStair(int p1x, int p1y, int p2x, int p2y) {
    while (true) {
        setPos(); 
        if (p1x <= x <= p2x && p1y <= y <= p2y) break; 
    }
}

int CheckCoord::getChamber() const {
    return chamber; 
}

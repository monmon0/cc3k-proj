#include "checkCoord.h"

#include <iostream>
#include <random>

int CheckCoord::giveRandomInt() {
    return prng(); 
}

void CheckCoord::setPos() {		
    while (true) {
        int chamber = prng() % 5;
        if (chamber == 0) {
            new_x = 3 + prng() % 26;
            new_y = 3 + prng() % 3;
        } else if (chamber == 1) {
            new_x = 4 + prng() % 21;
            new_y = 15 + prng() % 6;
        } else if (chamber == 2) {
            new_x = 38 + prng() % 12;
            new_y = 10 + prng() % 3;
        } else if (chamber == 3) {
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
        } else if (chamber == 4) {
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
            break; // Exit the loop if a valid position is found
        } 
    };
}

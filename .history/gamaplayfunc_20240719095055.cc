#include "gameplayfunc.h"

void RandomPos::setPos() {
    while (true) {
        int chamber = rand() % 5;
        if (chamber == 0) {
            new_x = 3 + rand() % 26;
            new_y = 3 + rand() % 3;
        } else if (chamber == 1) {
            new_x = 4 + rand() % 21;
            new_y = 15 + rand() % 6;
        } else if (chamber == 2) {
            new_x = 38 + rand() % 11;
            new_y = 10 + rand() % 2;
        } else if (chamber == 3) {
            int inner_chamber = rand() % 3;
            if (inner_chamber == 0) {
                new_x = 3 + rand() % 4;
                new_y = 39 + rand() % 4;
            } else if (inner_chamber == 1) {
                new_x = 61 + rand() % 9;
                new_y = 39 + rand() % 8;
            } else if (inner_chamber == 2) {
                new_x = 61 + rand() % 15;
                new_y = 8 + rand() % 6;
            }
        } else if (chamber == 4) {
            int inner_chamber = rand() % 2;
            if (inner_chamber == 0) {
                new_x = 36 + rand() % 39;
                new_y = 19 + rand() % 3;
            } else if (inner_chamber == 1) {
                new_x = 65 + rand() % 11;
                new_y = 16 + rand() % 3;
            }
        }

        if (curr->picture()->charAt(new_y, new_x, 1) == '.') {
            x = new_x;
            y = new_y;
            break; // Exit the loop if a valid position is found
        }
    };
}

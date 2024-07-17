#include <stdlib.h>

class RandomPos {
    int x, y;

    public:
        RandomPos() {
            int chamber = rand() % 5;
            if (chamber == 0) {
                x = 3 + rand() % 26;
                y = 3 + rand() % 3;
            } else if (chamber == 1) {
                x = 4 + rand() % 26;
                y = 15 + rand() % 6;
            } else if (chamber == 2) {

            } else if (chamber == 3) {

            } else if (chamber == 4) {
            } 

        };
        int getX();
        int getY();
};
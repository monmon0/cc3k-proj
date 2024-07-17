#include <stdlib.h>

class RandomPos {
    int x, y;

    public:
        RandomPos() {
            int chamber = rand() % 5;
            if (chamber == 0) {

            } else if (chamber == 1) {
            } else if (chamber == 2) {
            } else if (chamber == 3) {
            } else if (chamber == 4) {
            } 
            x = 2 + rand() % 79;
            y = 3 + rand() % 25;

        };
        int getX();
        int getY();
};
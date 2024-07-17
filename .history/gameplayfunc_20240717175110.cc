#include <stdlib.h>

class RandomPos() {
    int x;
    int y;
    public:
        RandomPos() {
            int chamber = rand() % 5;
            if (chamber == 1) {

            } else if  (chamber == 1) {
            x = 2 + rand() % 79;
            y = 3 + rand() % 25;

        };
        int getX();
        int getY();
}
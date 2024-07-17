#include <stdlib.h>

class RandomPos() {
    int x;
    int y;
    public:
        RandomPos() {
            x = 2 + rand() % 79;
            y = 2 + rand() % 25;
        };
        int getX();
        int getY();
}
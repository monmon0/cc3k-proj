#include <stdlib.h>

class RandomPos() {
    int x;
    int y;
    public:
        RandomPos() {
            x = rand() % 79;
            y = rand() % 25;
        };
        int getX();
        int getY();
}
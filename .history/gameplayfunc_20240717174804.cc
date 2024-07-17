#include <stdlib.h>

class RandomPos() {
    int x;
    int y;
    public:
        RandomPos() {
            x = 1+ (rand() % 79);
            y = 0;
        };
        int getX();
        int getY();
}
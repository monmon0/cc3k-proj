#include <stdlib.h>
#include 

class RandomPos() {
    int x;
    int y;
    public:
        RandomPos() {
            x = 2 + rand() % 79;
            y = 3 + rand() % 25;


        };
        int getX();
        int getY();
}
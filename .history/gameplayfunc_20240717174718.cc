#include <stdlib.h>

class RandomPos() {
    int x;
    int y;
//  1+ (rand() % 100). 
    public:
        RandomPos() {

            x = 0;
            y = 0;
        };
        int getX();
        int getY();
}
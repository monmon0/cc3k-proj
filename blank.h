#ifndef BLANK_H
#define BLANK_H
#include "asciiart.h"
#include <iostream>

class Blank: public AsciiArt {
    int x = 5, y = 18;
    public:
        char charAt(int row, int col, int tick) override;
        void shuffleStaireCase();
};

#endif

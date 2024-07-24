#ifndef STAIRCASE_H
#define STAIRCASE_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"

#include <string>

class Staircase : public Decorator {
    int x, y; 
    public:
        Staircase(AsciiArt *next, int x, int y);

        ~Staircase() = default; 
        AsciiArt *&nextChar() {return next;}
        char charAt(int row, int col);
};

#endif

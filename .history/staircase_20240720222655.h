#ifndef STAIRCASE_H
#define STAIRCASE_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"

#include <string>

class Staircase : public Item {
public:
    Staircase(AsciiArt *next, int x, int y);

    ~Staircase() = default; 

    charAt(int row, int col, int tick) = 0;
};

#endif

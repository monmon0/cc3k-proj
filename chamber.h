// blinkingbox.h
#ifndef CHAMBER_H
#define CHAMBER_H

#include "asciiart.h"
#include "decorator.h"

class Chamber : public Decorator {
    int top, bottom, left, right;

    public:
    Chamber(int t, int b, int l, int r, int door, int door_length, AsciiArt* next)
        : Decorator{next}, top{t}, bottom{b}, left{l}, right{r} {}

    char charAt(int row, int col, int tick) override;
};

#endif // CHAMBER_H

#ifndef ENEMIES_H
#define ∂

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"

#include <string>

class Staircase : public Item {
public:
    Staircase(AsciiArt *next, int x, int y);

    ~Staircase() = default; 
};

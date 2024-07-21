#ifndef ENEMIES_H
#define ENEMIES_H

#include "asciiart.h"
#include "Subject.h"
#include "Players.h"
#include "decorator.h"

#include <string>

class Staircase : public Item {
public:
    Staircase(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);

    ~Staircase() = default; 
};

#ifndef BLANK_H
#define BLANK_H
#include "asciiart.h"
#include <fstream>
#include <vector>
#include <iostream>

class Blank: public AsciiArt {
    std::string dungeonMap;
    public:
        Blank(const std::string &filename);
        char charAt(int row, int col) override;
        std::string &getMap();
};

#endif

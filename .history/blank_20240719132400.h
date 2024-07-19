#ifndef BLANK_H
#define BLANK_H
#include "asciiart.h"
#include <iostream>
#include <vector>

class Blank: public AsciiArt {
        std::vector<std::string> dungeonMap;
    public:
        Blank(const std::string& filename);
        char charAt(int row, int col, int tick) override;
};

#endif

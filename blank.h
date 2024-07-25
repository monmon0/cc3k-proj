#ifndef BLANK_H
#define BLANK_H
#include "asciiart.h"
#include <fstream>
#include <vector>

class Blank: public AsciiArt {
    std::string dungeonMap;
    public:
        Blank(const std::string &filename);
        Blank(const std::string &str, int floor);
        char charAt(int row, int col) override;
        std::string &getMap();
};

#endif

#ifndef BLANK_H
#define BLANK_H
#include "asciiart.h"
#include <fstream>
#include <vector>

class Blank: public AsciiArt {
<<<<<<< HEAD
        std::vector<std::string> dungeonMap;
=======
    int x = 5, y = 18;
    public:
        Blank(const std::string& filename);
        char charAt(int row, int col, int tick) override;
        void shuffleStaireCase();
};

#endif

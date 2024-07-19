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
>>>>>>> c5c7f49648cabd099ff2f1acf3ee72fa18cd4a5e
    public:
        Blank(const std::string& filename);
        char charAt(int row, int col, int tick) override;
        void shuffleStaireCase();
};

#endif

#include "blank.h"
#include <iostream>

Blank::Blank(const std::string& filename) {
    std::ifstream file(filename);

    std::string line;
    while (std::getline(file, line)) {
        dungeonMap.push_back(line);
    }
}


char Blank::charAt(int row, int col, int tick) { 
    // rewrite this to read from .txt file
    return dungeonMap[row][col]; 
} 


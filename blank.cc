#include "blank.h"
#include <iostream>
// #include "asciitext.h"

Blank::Blank(const std::string& filename) {
    std::ifstream file(filename);

    std::string line;
    while (std::getline(file, line)) {
        dungeonMap += line;
    }
}

Blank::Blank(const std::string &str, int floor) {
    dungeonMap = str;
}

char Blank::charAt(int row, int col) { 
    return dungeonMap[row * 79 + col]; 
} 

std::string &Blank::getMap() {
    return dungeonMap;
}



#include <iostream>
#include "dungeon.h"
#include "asciiart.h"
#include "chamber.h"
#include "blank.h"
#include <vector>
#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    // std::string command;

    // creating chambers
    // s.picture() = new Chamber{3, 9, 2, 28, s.picture()}; // remember to hardcode the dimension later

    s.render();
}
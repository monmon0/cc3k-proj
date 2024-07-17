#include "dungeon.h"
#include "asciiart.h"

#define ESC "\033["
#define LIGHT_BLUE "34"
#define RED "91"
#define RESET "\033[m"

// reset for new chambers?
void Dungeon::reset() { ticks = 0; }

void Dungeon::render() {
    // draws current map
    // 79 x 25
    for (int i = 0; i < rows - 5; ++i) {
        for (int j = 0; j < cols; ++j) {
            char curr = picture()->charAt(i, j, ticks);
        if (curr == '#' || curr == '@') {
            out << ESC << LIGHT_BLUE <<"m"<< picture()->charAt(i, j, ticks) << RESET;
        } else if (curr == 'E') {
            out << ESC << RED <<"m"<< picture()->charAt(i, j, ticks) << RESET;
        }
        else {
            out << picture()->charAt(i, j, ticks);
        }
        }
        out << std::endl;
    }
    // display stat

    //
    ++ticks;
}

Dungeon::~Dungeon() { delete thePicture; }

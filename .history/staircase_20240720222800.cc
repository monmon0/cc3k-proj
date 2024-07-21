#include "staircase.h"

Staircase::Staircase(AsciiArt *next, int x, int y)
    : Item(next, x, y, 0) {}

Staircase::charAt(int row, int col, int tick) char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick)
};

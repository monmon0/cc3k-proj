#include "staircase.h"

Staircase::Staircase(AsciiArt *next, int x, int y)
    : Decorator(next), x{x}, y, 0) {}

Staircase::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '\\';
    }
    return next->charAt(row, col, tick);
}

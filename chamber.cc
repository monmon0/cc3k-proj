#include "chamber.h"

char Chamber::charAt(int row, int col) {
    // border
    char curr = next->charAt(row, col);
    if ((col == left || col == right) && (row >= top && row <= bottom ) && curr != '.') {
        return '|';
    } else if ((top == row || bottom == row) && (col > left && col < right) && curr != '.') {
        return '-';
    }
    // floor tiles
    else if (row > top && row < bottom && col > left && col < right) {
        return '.';
    }
    return next->charAt(row, col);
}

#include "dungeon.h"
#include "asciiart.h"

// reset for new chambers?
void Dungeon::reset() { ticks = 0; }

void Dungeon::render() {
  // depends on different floor print out diff thing
  if (floor == 1) {
    // draws the first floor
    // 74 x 30
    out << '|';
    for (int j = 0; j < cols; ++j) out << '-';
    out << '|' << std::endl;
    for (int i = 0; i < rows - 6; ++i) {
      out << '|';
      for (int j = 0; j < cols; ++j) {
        out << picture()->charAt(i, j, ticks);
      }
      out << '|' << std::endl;
    }
    out << '|';
    for (int j = 0; j < cols; ++j) out << '-';
    out << '|' << std::endl;

    // make a printStat function in players, and print it here
    
  }
  ++ticks;
}

// not sure if need
// void Dungeon::animate(int numTicks) {
//   for (int i = 0; i < numTicks; ++i) render();
// }

Dungeon::~Dungeon() { 
  delete thePicture; }

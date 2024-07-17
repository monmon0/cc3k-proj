#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream>
class AsciiArt;

class Dungeon {
  // change rows n nums
  int rows = 30, cols = 79, ticks = 0;
  int floor = 1;                            // dungeon chamber number
  std::ostream &out = std::cout;           // print

  AsciiArt *thePicture;                  

 public:
  explicit Dungeon(AsciiArt *picture): thePicture{picture} {}

  AsciiArt *&picture() { return thePicture; }
  void render();
  void reset();
  void printStat();
  // void animate(int numTicks);
  ~Dungeon();
};

#endif

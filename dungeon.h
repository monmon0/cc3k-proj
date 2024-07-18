#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream>
#include "Players.h"
#include <string>

class AsciiArt;

class Dungeon {
  // change rows n nums
  int rows = 30, cols = 79, ticks = 0;
  std::ostream &out = std::cout;          
  AsciiArt *thePicture;             
  std::string action = "This player is losing their goddamn mind";

 public:
  explicit Dungeon(AsciiArt *picture): thePicture{picture} {}

  AsciiArt *&picture() { return thePicture; }
  void render(Player * p);
  void reset();
  void setAction(std::string a) {
    action += a;
  }
  void clearAction() {
    action = " ";
  }

  ~Dungeon();
};

#endif

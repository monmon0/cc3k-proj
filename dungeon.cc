#include "dungeon.h"
#include "asciiart.h"
#include <string>

#define ESC "\033["
#define LIGHT_BLUE "34"
#define RED "91"
#define RESET "\033[m"

// reset for new chambers?
void Dungeon::reset() { ticks = 0; }

void Dungeon::render(Player * player) {
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
  // print stat
  std::string race;
  if (player->getRace() == 's') {
    race = "Shade";
  }
  out << "Race: " << race << " Gold: " << player->getGold();
  // print spaces
  for (int i = 0; i < 54 - race.length(); i++) out << " ";
  out << "Floor: " << floor << std::endl;
  out << "HP: " << player->getHP() << std::endl;
  out << "Atk: " << player->getAtk() << std::endl;
  out << "Def: " << player->getDef() << std::endl;
  out << "Action: " << action << std::endl;
  //
  ++ticks;
}

Dungeon::~Dungeon() { delete thePicture; }

#include "dungeon.h"
#include "asciiart.h"
// #include "Enemies.h"
#include <string>

#define ESC "\033["
#define LIGHT_BLUE "34"
#define RED "91"
#define GREEN "92"
#define GOLD "93"
#define RESET "\033[m"

// reset for new chambers?
void Dungeon::reset() { ticks = 0; }

void Dungeon::render(Player * player) {
  // draws current map
  // 79 x 25
  for (int i = 0; i < rows - 5; ++i) {
    for (int j = 0; j < cols; ++j) {
      char curr = picture()->charAt(i, j, ticks);
      if (curr == '\\' || curr == '@') {
        out << ESC << LIGHT_BLUE <<"m"<< picture()->charAt(i, j, ticks) << RESET;
      } else if (curr == 'E' || curr == 'H' || curr == 'D' || curr == 'O' 
             || curr == 'L'  || curr == 'M'  || curr == 'R' || curr == 'W' ) {
        out << ESC << RED <<"m"<< picture()->charAt(i, j, ticks) << RESET;
      } else if (curr == 'P') {
         out << ESC << GREEN <<"m"<< picture()->charAt(i, j, ticks) << RESET;
      } else if (curr == 'G') {
         out << ESC << GOLD <<"m"<< picture()->charAt(i, j, ticks) << RESET;
      }
      else {
        out << picture()->charAt(i, j, ticks);
      }
    }
    out << std::endl;
  }
  // print stat
  std::string race;
  if (player->getRace() == 's') race = "Shade";
  if (player->getRace() == 'd') race = "Drow";
  if (player->getRace() == 'v') race = "Vampire";
  if (player->getRace() == 't') race = "Troll";
  if (player->getRace() == 'g') race = "Goblin";

  out << "Race: " << race << " Gold: " << player->getGold();
  // print spaces
  for (int i = 0; i < 54 - race.length(); i++) out << " ";
  out << "Floor: " << floor << std::endl;
  out << "HP: " << player->getHp() << std::endl;
  out << "Atk: " << player->getAtk() << std::endl;
  out << "Def: " << player->getDef() << std::endl;
  out << "Action: " << action << std::endl;
  //
  ++ticks;
}

Dungeon::~Dungeon() { delete thePicture; }

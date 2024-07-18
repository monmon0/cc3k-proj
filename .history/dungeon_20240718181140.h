#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Players.h"
#include "Enemies.h"

class AsciiArt;
class Enemy;

class Dungeon {
<<<<<<< HEAD
    int rows = 30, cols = 79, ticks = 0;
    std::ostream &out = std::cout;          
    AsciiArt *thePicture;             
    std::string action = "";
    std::vector<std::unique_ptr<Enemy>> enemies; 

public:
    explicit Dungeon(AsciiArt *picture): thePicture{picture} {}
=======
  // change rows n nums
  int rows = 30, cols = 79, ticks = 0;
  std::ostream &out = std::cout;          
  AsciiArt *thePicture;        
  std::string action = "";

  // std::vector<Enemy *> enemies;

 public:
  explicit Dungeon(AsciiArt *picture): thePicture{picture} {}
>>>>>>> 2587b65e66e9d568f90254e623f57e55cc6ce00b

    AsciiArt *&picture() { return thePicture; }
    void render(Player * p);
    void reset();
    void setAction(std::string a) {
        action += a;
    }
    void clearAction() { action = "";}
    void spawnEnemies();

<<<<<<< HEAD
    ~Dungeon();
=======
  // void createEnemies();

  // void createPotion() {};

  ~Dungeon();
>>>>>>> 2587b65e66e9d568f90254e623f57e55cc6ce00b
};

#endif // DUNGEON_H

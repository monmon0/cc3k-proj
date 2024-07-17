#include <iostream>
#include <vector>
#include <memory>   // For std::unique_ptr
#include "dungeon.h"
#include "asciiart.h"
#include "blank.h"
#include "decorator.h"
#include "players.h"
#include "enemies.h"

#include <string>

int main() {
    // display graphical interface
    AsciiArt *canvas = new Blank;

    Dungeon s{canvas};

    // std::string command;
    // Player * pc =  new Player{'s', s.picture(), 4, 6, 10, 10, 10};
    std::unique_ptr<Player> pc = Player::createPlayer('S', s.picture(), 4, 6, 100, 15, 10);
    std::unique_ptr<Enemy> h = Player::createPlayer('S', s.picture(), 4, 6, 100, 15, 10);

    s.picture() = pc.get();
    s.render();

    pc->move("ea", 1);
    s.render();
    pc->move("so", 1);
    s.render();

    // Clean up

}
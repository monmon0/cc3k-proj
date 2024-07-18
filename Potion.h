#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "Observer.h"
#include "PotionDecorator.h"
#include "Players.h"
#include <string>

// class Potion: public Decorator, public Observer {
//     int x;
//     int y;
//     string name;
//     int amt;

//     public:
//         Potion(AsciiArt *next, int x, int y, string name, int amt);
//         virtual void applyEffect(Player *player) = 0;
//         char charAt(int x, int y, int tick);
//         void notify(Player *player, int x, int y);
// }

// class RH: public Potion {
//     public:
//         RH(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
// }

// class BA: public Potion {
//     public:
//         BA(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
//         void undoEffect(Player *player) override;
// }

// class BD: public Potion {
//     public:
//         BD(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
//         void undoEffect(Player *player) override;
// }

// class PH: public Potion {
//     public:
//         PH(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
// }

// class WA: public Potion {
//     public:
//         WA(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
//         void undoEffect(Player *player) override;
// }

// class WD: public Potion {
//     public:
//         WD(AsciiArt *next, int x, int y, string name, int amt);
//         void applyEffect(Player *player) override;
//         void undoEffect(Player *player) override;
// }

#endif

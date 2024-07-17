#include "players.h"
#include "decorator.h"
#include <iostream>
#include<string>

Player::Player(char race, AsciiArt * next, int x, int y): Decorator{next}, race{race}, x{x}, y{y} {
    hp = 10, atk = 10, def = 10;
}

char Player::charAt(int row, int col, int tick) {
    if (row == y && col == x) {
        return '@';
    }
    return next->charAt(row, col, tick);
}

void Player::loseHP(int x) {
    hp -= x;
}

void Player::move(std::string dir, int tick) {
    // no,so,ea,we,ne,nw,se,sw
    // new block 
    int new_block_x = 0;
    int new_block_y = 0;
    char pos_check = ' ';

        if (dir == "no") {
            new_block_y--;
        } else if (dir == "so") {
            new_block_y++;
        } else if (dir == "ea") {
            new_block_x++;
        } else if (dir == "we") {
            new_block_x--;
        } else if (dir == "ne") {
            new_block_x++;
            new_block_y--;
        } else if (dir == "nw") {
            new_block_x--;
            new_block_y--;
        } else if (dir == "se") {
            new_block_x++;
            new_block_y++;
        }
        else if (dir == "sw") {
            new_block_x--;
            new_block_y++;
        }
        pos_check = next->charAt(x + new_block_x, y + new_block_y, tick);
        if (pos_check == '-' && pos_check == '|' && pos_check == ' ') ;
    
    x += new_block_x;
    y += new_block_y;
}

//  if (dir == "no") {
//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x, y - new_block, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         y -= new_block - 1;

//     } else if (dir == "so") {
//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x, y + new_block, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         y += new_block - 1;
//     } else if (dir == "ea") {
//         pos_check = next->charAt(x + new_block, y, tick);
       
//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x + new_block, y, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         x += new_block - 1;
//     } else if (dir == "we") {
//         pos_check = next->charAt(x - new_block, y, tick);

//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x - new_block, y, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         x -= new_block - 1;
//     }  else if (dir == "ne") {
//         pos_check = next->charAt(x + new_block, y - new_block, tick);

//          while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x + new_block, y - new_block, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         y -= new_block - 1;
//         x += new_block - 1;

//     }  else if (dir == "nw") {

//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x - new_block, y - new_block, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         x -= new_block - 1;
//         y -= new_block - 1;

//     }  else if (dir == "se") {

//         while (new_block <= 8) {
//             new_block++;
//             pos_check = next->charAt(x + new_block, y + new_block,, tick);
//             if (pos_check == '-' && pos_check == '|' && pos_check == ' ') break;
//         }
//         x += new_block - 1;
//         y += new_block - 1;

//     }  else if (dir == "sw") {
//         pos_check = next->charAt(x - new_block, y, tick);

//         while (pos_check != '.' && pos_check != '#' && pos_check != '\\' && new_block > 0) {
//             new_block--;
//             pos_check = next->charAt(x - new_block, y, tick);
//         }
//         x -= new_block;
//     }
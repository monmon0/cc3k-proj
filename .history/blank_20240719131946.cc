#include "blank.h"
#include <iostream>

char Blank::charAt(int row, int col, int tick) { 
    // rewrite this to read from .txt file
    const char *DungeonMap = 
"|-----------------------------------------------------------------------------|
"|                                                                             |"
"| |--------------------------|        |-----------------------|               |"
"| |..........................|        |.......................|               |"
"| |..........................+########+.......................|-------|       |"
"| |..........................|   #    |...............................|--|    |"
"| |..........................|   #    |..................................|--| |"
"| |----------+---------------|   #    |----+----------------|...............| |"
"|            #                 #############                |...............| |"
"|            #                 #     |-----+------|         |...............| |"
"|            #                 #     |............|         |...............| |"
"|            ###################     |............|   ######+...............| |"
"|            #                 #     |............|   #     |...............| |"
"|            #                 #     |-----+------|   #     |--------+------| |"
"|  |---------+-----------|     #           #          #              #        |"
"|  |.....................|     #           #          #         |----+------| |"
"|  |.....................|     ########################         |...........| |"
"|  |.....................|     #           #                    |...........| |"
"|  |.....................|     #    |------+--------------------|...........| |"
"|  |.....................|     #    |.......................................| |"
"|  |.....................+##########+.......................................| |"
"|  |.....................|          |.......................................| |"
"|  |---------+-----------|          |---------------------------------------| |"
"|                                                                             |"
"|-----------------------------------------------------------------------------|";

    return DungeonMap[row * 79 + col]; 
} 


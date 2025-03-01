#include "blank.h"
#include <iostream>

Blank::Blank(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        dungeonMap.push_back(line);
    }
}


char Blank::charAt(int row, int col, int tick) { 
    // rewrite this to read from .txt file
    const char *DungeonMap = 
"|-----------------------------------------------------------------------------|\
|                                                                             |\
| |--------------------------|        |-----------------------|               |\
| |..........................|        |.......................|               |\
| |..........................+########+.......................|-------|       |\
| |..........................|   #    |...............................|--|    |\
| |..........................|   #    |..................................|--| |\
| |----------+---------------|   #    |----+----------------|...............| |\
|            #                 #############                |...............| |\
|            #                 #     |-----+------|         |...............| |\
|            #                 #     |............|         |...............| |\
|            ###################     |............|   ######+...............| |\
|            #                 #     |............|   #     |...............| |\
|            #                 #     |-----+------|   #     |--------+------| |\
|  |---------+-----------|     #           #          #              #        |\
|  |.....................|     #           #          #         |----+------| |\
|  |.....................|     ########################         |...........| |\
|  |.....................|     #           #                    |...........| |\
|  |.....................|     #    |------+--------------------|...........| |\
|  |.....................|     #    |.......................................| |\
|  |.....................+##########+.......................................| |\
|  |.....................|          |.......................................| |\
|  |---------+-----------|          |---------------------------------------| |\
|                                                                             |\
|-----------------------------------------------------------------------------|";

    return DungeonMap[row * 79 + col]; 
} 


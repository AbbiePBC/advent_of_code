//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec13_fns.h"


int main () {
    std::ifstream file ("../../Dec13/input.txt");

    if (file.is_open())
    {
        AllCoords input(file);
        file.close();
    }
    else std::cout << "Unable to open file";

    return 0;
}


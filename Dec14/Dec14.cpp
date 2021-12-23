//
// Created by Abbie Currington on 23/12/2021.
//

#include "Dec14_fns.h"



int main () {
    std::ifstream file ("../../Dec14/test_input.txt");

    if (file.is_open())
    {
        Polymer input(file);
        file.close();
    }
    else std::cout << "Unable to open file";

    return 0;

}


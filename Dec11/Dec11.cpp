//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec11_fns.h"


int main () {
    std::ifstream file ("../../Dec11/input.txt");

    if (file.is_open())
    {
        const int num_steps = 100;
        Octopods octopods(file, num_steps);
        file.close();
    }
    else std::cout << "Unable to open file";

    return 0;
}

//
// Created by Abbie Currington on 08/12/2021.
//

#include "Dec6_fns.h"

const int reproduction_days = 256;

int main () {
    std::string line;
    std::ifstream file("../Dec6_input.txt");
    std::vector<std::int64_t > fish(max_days, 0); // define size of 9, initialise to zero
    std::int64_t tot = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            tot += store_input_count_fish(line, fish);
            for (int i = 0; i < reproduction_days; i ++){
                tot += update_fish(fish);
            }
        }
        std::cout<<"number of fish: "<< tot<<std::endl;
        file.close();
    }

    else std::cout << "Unable to open file";

    return 0;
}
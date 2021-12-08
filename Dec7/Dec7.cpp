//
// Created by Abbie Currington on 08/12/2021.
//


#include "Dec7_fns.h"

int main () {
    std::string line;
    //TODO use relative path?
    std::ifstream file ("/Users/abbiecurrington/Desktop/Advent of Code/Dec7/Dec7_input.txt");
    std::vector<int> displacement(max_displacement, 0);
    if (file.is_open())
    {
        int min_fuel = implausibly_big_number;
        while ( getline (file,line) )
        {
            // the following won't work properly if the input code is over multiple lines
            // but input is a single line so will ignore this
            displacement = store_displacements(line);

                for (int i = 0; i < max_displacement; i++){
                    //TODO could put a check in here to see which part we're doing,
                    // but this would have to be evaluated each time :/
                    // could check before the for loop, but this could cause repetition of code
                    //std::int64_t fuel = calc_fuel_consumption_part_1(displacement, i);
                    std::int64_t fuel = calc_fuel_consumption_part_2(displacement, i);
                    if (fuel < min_fuel){
                        min_fuel = fuel;
                    }
                }
        }
        file.close();
        std::cout<<"result: "<<min_fuel<<std::endl;
    }
    else std::cout << "Unable to open file";

    return 0;
}
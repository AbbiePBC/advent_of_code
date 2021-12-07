//
// Created by Abbie Currington on 02/12/2021.
//

// read input file of numbers and determine how many times the number increases compared to the previous line

#include <iostream>
#include <fstream>
#include <string>

class GroupOfThree{
    public:
        int int_line, prev_line, prev_prev_line;
};


void single_increases(GroupOfThree *input, int *num_inc){
    if (input->int_line > input->prev_line)
    {
        (*num_inc) ++;
    }
    input->prev_line = input->int_line;
}


void window_increases(GroupOfThree *input, int *prev_sub_tot, int *win_inc){
    int sub_tot = input->int_line + input->prev_line + input->prev_prev_line;
    if (sub_tot > *prev_sub_tot)
    {
        (*win_inc) ++;
    }
    input->prev_prev_line = input->prev_line;
    *prev_sub_tot = sub_tot;
}


int main () {
    std::string line;
    std::ifstream file ("../Dec1_input.txt");

    int num_inc = -1; // initialise as -1 to account for first comparison
    int win_inc = -3;
    // to account for first three comparisons, which will show increases as fewer numbers are included
    GroupOfThree input = {0,0,0};
    int prev_sub_tot = 0;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            input.int_line = stoi(line);
            window_increases(&input, &prev_sub_tot,&win_inc);
            // sliding window fn must go first as single_increases updates val of prev_line
            single_increases(&input, &num_inc);
        }
        file.close();
        std::cout << "Single increases: " << num_inc << '\n';
        std::cout << "Window increases: " << win_inc << '\n' << std::flush;

    }
    else std::cout << "Unable to open file";

    return 0;
}
//
// Created by Abbie Currington on 08/12/2021.
//
#include "Dec6_fns.h"

std::int64_t store_input_count_fish(std::string line, std::vector<std::int64_t> &fish){
    //std::vector<int> fish(max_days, 0); // define size of 9, initialise to zero
    uint line_idx = 0;
    std::int64_t num_fish = 0;
    // store input <- single chars separated by ',', by definition.
    while (line_idx < line.size()){
        //extract num and store in vector
        int fish_days = line[line_idx] - '0';
        fish[uint(fish_days)] ++;
        line_idx +=2; //skip char then comma
        num_fish++;
    }
    return num_fish;
}

std::int64_t update_fish(std::vector<std::int64_t> &fish){
    std::int64_t new_fish = fish[0];
    for (int i = 0 ; i < max_days; i++){
        fish[i] = fish[i+1];
    }
    fish[max_days - 1] = new_fish; // -1 to give idx; max_days = 9 but idx 8
    fish[old_fish_max_days] += new_fish;

    return new_fish;
}
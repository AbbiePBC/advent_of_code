//
// Created by Abbie Currington on 08/12/2021.
//

#include "Dec7_fns.h"

std::vector<int> store_displacements(std::string line){
    std::vector<int> displacement(max_displacement, 0);
    std::string delimiter = ",";
    while (line.size() > 2){
        //TODO would prefer to keep track of idx here, but updating string doesn't change string.size()
        std::string str_displ = line.substr(0, line.find(delimiter));
        displacement[stoi(str_displ)] ++;
        line.erase(0, line.find(delimiter) + delimiter.length());
    }
    return displacement;
}

std::int64_t calc_fuel_consumption_part_1(const std::vector<int> &displacement, int displ_idx){
    std::int64_t fuel_used = 0;
    for (int i = 0; i < max_displacement; i ++){
        fuel_used += (abs(i - displ_idx))*(displacement[i]);
    }
    return fuel_used;
}

std::int64_t calc_fuel_consumption_part_2(const std::vector<int> &displacement, int displ_idx){
    std::int64_t fuel_used = 0;
    for (int i = 0; i < max_displacement; i ++){
        fuel_used += ((triangle_num(abs(i - displ_idx)))*(displacement[i]));
    }
    return fuel_used;
}

std::int64_t triangle_num(int input){
    int result = 0;
    for (int i = 1 ; i < input + 1; i ++){ // no point doing this for i == 0
        result += i;
    }
    return result;
}
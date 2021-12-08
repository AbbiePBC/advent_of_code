//
// Created by Abbie Currington on 08/12/2021.
//

#ifndef ADVENTOFCODE_DEC6_FNS_H
#define ADVENTOFCODE_DEC6_FNS_H

#include <iostream>
#include <fstream>
#include <vector>

const int max_days = 9;
const int old_fish_max_days = 6;

int store_input_count_fish(std::string line, std::vector<int> &fish);
int update_fish(std::vector<int> &fish);

#endif //ADVENTOFCODE_DEC6_FNS_H


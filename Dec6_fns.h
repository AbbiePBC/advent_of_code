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

std::int64_t store_input_count_fish(std::string line, std::vector<std::int64_t > &fish);
std::int64_t update_fish(std::vector<std::int64_t > &fish);

#endif //ADVENTOFCODE_DEC6_FNS_H


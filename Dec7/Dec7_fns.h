//
// Created by Abbie Currington on 08/12/2021.
//

#ifndef ADVENTOFCODE_DEC7_FNS_H
#define ADVENTOFCODE_DEC7_FNS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int max_displacement = 2000 + 1;
const std::int64_t implausibly_big_number = 9999999999;

std::vector<int> store_displacements(std::string line);
std::int64_t calc_fuel_consumption_part_1(const std::vector<int> &displacement, int displ_idx);
std::int64_t calc_fuel_consumption_part_2(const std::vector<int> &displacement, int displ_idx);
std::int64_t triangle_num(int input);

#endif //ADVENTOFCODE_DEC7_FNS_H

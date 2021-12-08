//
// Created by Abbie Currington on 08/12/2021.
//

#ifndef ADVENTOFCODE_DEC8_FNS_H
#define ADVENTOFCODE_DEC8_FNS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int signals_1 = 2;
const int signals_4 = 4;
const int signals_7 = 3;
const int signals_8 = 7;

std::vector<std::string> extract_output(std::string line);
int count_unique_num_segments(std::vector<std::string> output_strings);

#endif //ADVENTOFCODE_DEC8_FNS_H

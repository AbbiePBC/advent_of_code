//
// Created by Abbie Currington on 08/12/2021.
//

#ifndef ADVENTOFCODE_DEC8_FNS_H
#define ADVENTOFCODE_DEC8_FNS_H

#ifndef part_one
#define part_one 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int signals_1 = 2;
const int signals_4 = 4;
const int signals_7 = 3;
const int signals_8 = 7;

const int num_inputs = 10;
const int num_outputs = 4;

int count_unique_num_segments(const std::vector<std::string> &output_strings);
void extract_strings(std::string line, std::vector<std::string> &input, std::vector<std::string> &output);
std::vector<char> find_chars_for_1(const std::vector<std::string> &vec);
char find_top_line(const std::string &three_letter_input, const std::vector<char> &two_letter_vector);

#endif //ADVENTOFCODE_DEC8_FNS_H

#endif //part_one
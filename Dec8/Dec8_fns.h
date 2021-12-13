//
// Created by Abbie Currington on 08/12/2021.
//

#ifndef ADVENTOFCODE_DEC8_FNS_H
#define ADVENTOFCODE_DEC8_FNS_H

#ifndef part_one
#define part_one 0

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

const int signals_1 = 2;
const int signals_4 = 4;
const int signals_7 = 3;
const int signals_8 = 7;

const int num_inputs = 10;
const int num_outputs = 4;

int count_unique_num_segments(const std::vector<std::string> &output_strings);
void extract_strings(std::string line, std::vector<std::string> &input, std::vector<std::string> &output);
std::vector<char> find_chars(const std::string&vec, const int &size);
void find_right_top(const std::vector<std::string> &input_strings, const std::vector<char> &two_letter_vector,
                    char &right_top, char &right_bottom);
int decode_output_strings(const char &right_top, const char &right_bottom,
                  const std::vector<std::string> &output_strings,
                  const std::vector<char> &four_letter_vector);
int find_6_digit_number(const std::string &current_string, const char &right_top, const std::vector<char> &chars_for_4);
int find_5_digit_number(const std::string &current_string, const char &right_top, const char &right_bottom);
int find_0_or_9(const std::string &current_string, const std::vector<char> &chars_for_4);

#endif //ADVENTOFCODE_DEC8_FNS_H

#endif //part_one
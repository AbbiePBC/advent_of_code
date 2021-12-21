//
// Created by Abbie Currington on 15/12/2021.
//

#ifndef ADVENTOFCODE_DEC10_FNS_H
#define ADVENTOFCODE_DEC10_FNS_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


class Bracket{
public:
    char open;
    char close;
    int part_one_score;
    Bracket(char a, char b, int score){
        open = a;
        close = b;
        part_one_score = score;
    }
};


class Strings{
public:
    std::vector<std::string> initial_strings;
    std::vector<std::string> edited_strings;
    int p1_score;

    std::vector<std::string> extract_and_store_strings(std::ifstream &ifstream);
    static std::vector<std::string> remove_complete_uncorrupted_lines(const std::vector<std::string> &strings, const std::vector<Bracket> &brackets);
    int check_string(const std::vector<std::string> &edited_strings, const std::vector<Bracket> &brackets);

    Strings(std::ifstream &file, const std::vector<Bracket> &brackets){
        initial_strings = extract_and_store_strings(file);
        edited_strings = remove_complete_uncorrupted_lines(initial_strings, brackets);
        p1_score = check_string(edited_strings, brackets);
    }
};

std::vector<u_int64_t> remove_incomplete_lines(const std::vector<std::string> &strings, int &part_one_result, const std::vector<Bracket> &brackets);
uint64_t find_string_score(const std::string &edited_string, const std::vector<Bracket> &brackets);




#endif //ADVENTOFCODE_DEC10_FNS_H

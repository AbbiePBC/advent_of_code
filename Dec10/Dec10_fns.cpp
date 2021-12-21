//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec10_fns.h"

std::vector<std::string> Strings::extract_and_store_strings(std::ifstream &file){

    std::vector<std::string > strings;
    std::string line;
    while ( getline (file,line) ){
        strings.push_back(line);
    }
    return strings;
}


std::vector<std::string> Strings::remove_complete_uncorrupted_lines(const std::vector<std::string> &strings,
                                                                    const std::vector<Bracket> &brackets){
    int num_strings = strings.size();
    std::vector<std::string> edited_strings;
    for (int i = 0; i < num_strings; i++){
        std::string str_cpy = strings[i];
        for (int x = str_cpy.size()-1; x >= 0; x --){
            for (int j = x; j >= 0; j --){ // down to 1 to allow comparison to the end
                // decreasing so that idxs aren't affected.
                for (auto bracket: brackets){
                    if (str_cpy[j] == bracket.open && str_cpy[j+1] == bracket.close){
                        str_cpy.erase (j,2);
                    }
                }
            }
        }
        if (!str_cpy.empty()){
            // use for p1
            edited_strings.push_back(str_cpy);
        }

    }
    return edited_strings;
}



int Strings::check_strings(const std::vector<std::string> &edited_strings, const std::vector<Bracket> &brackets){
    int score = 0;
    for (auto string: edited_strings){
        check_string(// if close bracket, return score, else return 0);
    }
    return score;
}


int find_match(const std::string &edited_string, const int &j, const std::vector<Bracket> &brackets){
    for (int x = 0; x < brackets.size(); x ++){
        if (edited_string[j] == brackets[x].open){
            return x+1;
        }
    }
    return 0;
}

uint64_t find_string_score(const std::string &string, const std::vector<Bracket> &brackets){
    uint64_t score = 0;
    for (int j = string.size() - 1; j > -1 ; j --){
        int tmp = find_match(string, j, brackets);
        if (tmp != 0){
            score = score*5 + tmp;
        }
    }
    return score;
}

std::vector<uint64_t> remove_incomplete_lines(const std::vector<std::string> &strings, int &score, const std::vector<Bracket> &brackets){
    int num_strings = strings.size();
    std::vector<uint64_t> part_two_scores;
    for (int i = 0; i < num_strings; i++){
        std::string edited_string = check_string(strings[i], score, brackets);
        if (edited_string.empty()){
            part_two_scores.push_back(find_string_score(strings[i], brackets));
        }
    }
    return part_two_scores;
}


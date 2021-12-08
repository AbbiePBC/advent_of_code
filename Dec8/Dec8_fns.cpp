//
// Created by Abbie Currington on 08/12/2021.
//

#include "Dec8_fns.h"

std::vector<std::string> extract_output(std::string line){
    std::string delimiter = "| ";
    line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    std::vector<std::string> output_strings;
    while (output_strings.size() < 4){
        delimiter = " ";
        std::string word = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        //in final case, delim is '\0', which causes line to be full length
        //line.substring is then == line, and can be directly added to vector
        output_strings.push_back(word);
    }
    return output_strings;
}

int count_unique_num_segments(std::vector<std::string> output_strings){
    int num_segments = 0;

    for (int i = 0; i < output_strings.size(); i++){
        int str_len = output_strings[i].size();
        //std::cout<<output_strings[i].size()<<std::endl;
        if (str_len == signals_1 || str_len == signals_4 ||
            str_len == signals_7 || str_len == signals_8 ){
            num_segments ++;
        }
    }
    return num_segments;
}
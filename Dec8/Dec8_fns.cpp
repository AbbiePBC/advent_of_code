//
// Created by Abbie Currington on 08/12/2021.
//

#include "Dec8_fns.h"

void store_strings(std::string line, std::string delimiter, std::vector<std::string> &vec, int num_strings){
    line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());

    while (vec.size() < num_strings){
        delimiter = " ";
        std::string word = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        //in final case, delim is '\0', which causes line to be full length
        //line.substring is then == line, and can be directly added to vector
        vec.push_back(word);

    }

}

std::vector<char> find_chars_for_1(const std::vector<std::string> &vec){
    std::vector<char> chars_for_1 ;
    for (int i = 0; i < num_inputs; i ++){
        std::cout<<vec[i]<<std::endl;
        std::cout<<vec[i].size()<<std::endl;

        if (vec[i].size() == 2){
            std::string string_for_one = vec[i];
            chars_for_1.push_back(string_for_one[0]);
            chars_for_1.push_back(string_for_one[1]);
            return chars_for_1;
        }
    }

    return chars_for_1;
}

void extract_strings(std::string line, std::vector<std::string> &input, std::vector<std::string> &output){
    int num_strings = num_outputs;
    std::string delimiter;
    std::string line_cpy = line;

    if(!part_one){
        delimiter = "";
        std::cout << "delim length "<<delimiter.length()<<std::endl;
        num_strings = num_inputs;
        store_strings(line_cpy, delimiter, input, num_strings);
        num_strings = num_outputs;
    }

    delimiter = " | ";
    store_strings(line, delimiter, output, num_strings);
}


int count_unique_num_segments(const std::vector<std::string> &output_strings){
    int num_segments = 0;

    for (int i = 0; i < output_strings.size(); i++){
        int str_len = output_strings[i].size();
        if (str_len == signals_1 || str_len == signals_4 ||
            str_len == signals_7 || str_len == signals_8 ){
            num_segments ++;
        }
    }
    return num_segments;
}

char find_top_line(const std::string &three_letter_input, const std::vector<char> &two_letter_vector){
    char top_line =  'z'; // not in possible outputs
    for (int i = 0; i < 3; i++){
        if(!(three_letter_input[i] == two_letter_vector[0] || three_letter_input[i] == two_letter_vector[1])) {
            top_line = three_letter_input[i];
            return top_line;
        }
    }
    return top_line;
}
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

std::vector<char> find_chars(const std::string &input, const int &len){
    std::vector<char> char_vec;
    for (int i = 0; i < len; i ++){
        char_vec.push_back(input[i]);
    }
    return char_vec;
}


void extract_strings(std::string line, std::vector<std::string> &input, std::vector<std::string> &output){
    int num_strings = num_outputs;
    std::string delimiter;
    std::string line_cpy = line;

    if(!part_one){
        delimiter = "";
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

void find_right_top(const std::vector<std::string> &input_strings, const std::vector<char> &two_letter_vector,
                    char &right_top, char &right_bottom){
    std::string current;
    std::vector<std::string> strings_of_len_6;
    for (int i = 0; i < input_strings.size(); i ++){
        current = input_strings[i];
        if (current.size() == 6){
            strings_of_len_6.push_back(current);
        }
    }
    int num_digits = 6;

    for (int j = 0; j < strings_of_len_6.size(); j++){
        current = strings_of_len_6[j];
        bool found_char_1 = false;
        bool found_char_2 = false;
        char possible_right_bottom= 'z';

        for (int i = 0; i < num_digits; i ++) {
            if ((current[i] == two_letter_vector[0]) && !found_char_1) {
                possible_right_bottom = current[i];
                found_char_1 = true;
            }
            if ((current[i] == two_letter_vector[1]) && !found_char_2) {
                possible_right_bottom = current[i];
                found_char_2 = true;
            }
        }
        // can make more efficient and lose bools by comparing with 'z' or similar
        if ((found_char_1 && !found_char_2) || (!found_char_1 && found_char_2)){
            if (possible_right_bottom == two_letter_vector[0]){
                right_bottom = possible_right_bottom;
                right_top = two_letter_vector[1];
                return;
            }
            else if (possible_right_bottom == two_letter_vector[1]){
                right_top = two_letter_vector[0];
                right_bottom = two_letter_vector[1];
                return;
            }
        }
    }
}


// the find_X_digit number fns could be combined relatively easily, but for readability I'll keep them separate
int find_5_digit_number(const std::string &current_string, const char &right_top, const char &right_bottom){
    bool found_right_top = false;
    bool found_right_bottom = false;
    int strlen = 5;
    for (int i = 0; i < strlen; i++){
        if (current_string[i] == right_top){
            found_right_top = true;
        }
        else if (current_string[i] == right_bottom){
            found_right_bottom = true;
        }
    }
    if(found_right_top && found_right_bottom){
        return 3;
    }
    else if (found_right_top){
        return 2;
    }
    else if (found_right_bottom){
        return 5;
    }
    else{
        std::cout<<"error";
    }
    return 0;
}

int find_0_or_9(const std::string &current_string, const std::vector<char> &chars_for_4){
    for (int j = 0; j < 4; j++) {
        bool looking_for_digit = true;
        for (int i = 0; i < 6; i ++) {
            if (chars_for_4[j] == current_string[i]) {
                looking_for_digit = false;
                break;
            }
        }
        if (looking_for_digit){
            // i.e. haven't found all four lines that comprise a 4
            return 0;
        }
    }
    return 9;
}

int find_6_digit_number(const std::string &current_string, const char &right_top,
                        const std::vector<char> &chars_for_4){
    bool found_right_top = false;
    int strlen = 6;
    int digit = -1;
    for (int i = 0; i < strlen; i++){
        if (current_string[i] == right_top){
            found_right_top = true;
            break;
        }
    }
    if(!found_right_top){
        return 6;
    }
    else{
        // 0_or_9
        digit = find_0_or_9(current_string, chars_for_4);
    }
    return digit;
}

int decode_output_strings(const char &right_top, const char &right_bottom,
                  const std::vector<std::string> &output_strings,
                  const std::vector<char> &four_letter_vector){
    int line_result = 0;
    int num_outputs = output_strings.size();
    for (int j = 0; j < num_outputs; j ++) {
        std::string current_string = output_strings[j];
        int strlen = current_string.size();
        enum {length_1 = 2, length_7 = 3, length_4 = 4, length_5 = 5, length_6 = 6, length_8 = 7};
        switch(strlen){
            case length_1:
                line_result += 1*pow(10,num_outputs-j-1);
                break;
            case length_7:
                line_result += 7*pow(10,num_outputs-j-1);
                break;
            case length_4:
                line_result += 4*pow(10,num_outputs-j-1);
                break;
            case length_8:
                line_result += 8*pow(10,num_outputs-j-1);
                break;
            case length_5:{
                int tmp = find_5_digit_number(current_string, right_top, right_bottom);
                line_result += tmp*pow(10,num_outputs-j-1);
                break;
            }
            case length_6: {
                int tmp = find_6_digit_number(current_string, right_top, four_letter_vector);
                line_result += tmp * pow(10, num_outputs-j-1);
                break;
            }
        }
        //std::cout<<string_representations[i]<<std::endl;
    }
    return line_result;
}
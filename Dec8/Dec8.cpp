//
// Created by Abbie Currington on 08/12/2021.
//


//
// Created by Abbie Currington on 08/12/2021.
//


#include "Dec8_fns.h"


int main () {
    std::string line;
    //TODO use relative path?
    std::ifstream file ("/Users/abbiecurrington/Desktop/Advent of Code/Dec8/Dec8_input.txt");
    int unique_num_segments = 0;
    std::int32_t part_two_result = 0;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::vector<std::string> input_strings; // only used for part two
            std::vector<std::string> output_strings;
            extract_strings(line, input_strings, output_strings);

            if(part_one){
                unique_num_segments += count_unique_num_segments(output_strings);
            }else{
                //part_two
                std::vector<char> two_letter_vector;
                std::vector<char> four_letter_vector;
                char right_top = 'z';
                char right_bottom = 'z';
                const enum {two_letters =2, four_letters =4};
                //find chars for 1,8,7,4 first, as these are unique for lengths
                for (int i = 0 ; i < input_strings.size(); i++) {
                    if (input_strings[i].size() == 2) {
                        // can merge these two functions since they do the same thing
                        two_letter_vector = find_chars(input_strings[i], two_letters);
                    }
                    else if (input_strings[i].size() == 4){
                        four_letter_vector = find_chars(input_strings[i], four_letters);
                    }
                }
                //then identify other values
                find_right_top(input_strings, two_letter_vector, right_top, right_bottom);
                //after identifying both top and bottom right, can use this to identify remaining two digits
                int line_result = decode_output_strings(right_top, right_bottom, output_strings, four_letter_vector);
                part_two_result += line_result;
            }
        }
        file.close();
        std::cout<<"part 1 result: "<<unique_num_segments<<std::endl;
        std::cout<<"part 2 result: "<<part_two_result<<std::endl;


    }
    else std::cout << "Unable to open file";

    return 0;
}

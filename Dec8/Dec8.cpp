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

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::vector<std::string> input_strings; // only used for part two
            std::vector<std::string> output_strings;
            extract_strings(line, output_strings, output_strings);
            if(part_one){
                unique_num_segments += count_unique_num_segments(output_strings);
            }else{
                //part_two
                //then identify other values

            }
        }
        file.close();
        std::cout<<"part 1 result: "<<unique_num_segments<<std::endl;
    }
    else std::cout << "Unable to open file";

    return 0;
}

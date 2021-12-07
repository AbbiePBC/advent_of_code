//
// Created by Abbie Currington on 03/12/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

enum Type { o2, co2};

int convert_to_dec(std::string binary){
    int var = 0;
    int len = binary.size();
    for (int i = 0; i < len; i ++)
    {
        var += (binary[i] - '0') << (len - i - 1); // bitshift
    }
    return var;
}


std::vector<std::string> update_vector(std::vector<std::string> inputs, char wanted_digit, int str_idx){
    for (int i = inputs.size() - 1; i >= 0; i--) // so that idxs are unaffected by erasure
    {
        if (inputs[i][str_idx] != wanted_digit)
        {
            inputs.erase(inputs.begin() + i);
        }
    }
    return inputs;
}


int part_two(std::vector<std::string> inputs, int method){
    int str_idx = 0;
    while (inputs.size() > 1)
    {
        int ones = 0;
        //count occurrences of 'ones'
        for (int i = 0; i < inputs.size(); i++)
        {
            if (inputs[i][str_idx] == '1'){
                ones ++;
            }
        }
        //decide whether we want to keep ones or zeroes depending on input
        int wanted_digit = '1';
        switch (method){
            case o2:
                wanted_digit = (ones*2 >= inputs.size()) ? '1' : '0';
                break;
            case co2:
                wanted_digit = (ones*2 < inputs.size()) ? '1' : '0';
                break;
        }

        inputs = update_vector(inputs, wanted_digit, str_idx);
        str_idx ++;
    }
    return convert_to_dec(inputs[0]);
}


int main () {
    std::string line;
    std::ifstream file ("../Dec3_input.txt");

    int line_count = 0;
    std::vector<std::string> inputs;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            inputs.push_back(line);
        }
        int result2 = part_two(inputs, co2) * part_two (inputs, o2); // most common first digit in updated array[0]; others will change wrt time
        std::cout << "Part Two result: " << result2 << '\n';
    }

    else std::cout << "Unable to open file";

    return 0;
}
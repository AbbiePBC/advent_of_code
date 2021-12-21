//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec10_fns.h"


int main () {
    std::ifstream file ("../../Dec10/Dec10_input.txt");

    if (file.is_open())
    {
        std::vector<Bracket> brackets;
        brackets.reserve(4);
        brackets.emplace_back('(', ')', 3);
        brackets.emplace_back('[', ']', 57);
        brackets.emplace_back('{', '}', 1197);
        brackets.emplace_back('<', '>', 25137);

        Strings all_string_info(file, brackets);
        file.close();
        std::vector<uint64_t> part_two_scores = remove_incomplete_lines(all_string_info.edited_strings, all_string_info.p1_score, brackets);

        std::cout<<"part 1 result: "<<all_string_info.p1_score<<std::endl;
        std::sort(part_two_scores.begin(), part_two_scores.end());
        std::cout<<"part 2 result: "<<part_two_scores[part_two_scores.size()/2]<<std::endl;
    }
    else std::cout << "Unable to open file";

    return 0;
}

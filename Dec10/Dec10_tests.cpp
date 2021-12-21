//
// Created by Abbie Currington on 15/12/2021.
//

#include "gtest/gtest.h"
#include "Dec10_fns.h"

TEST(Dec10, test_extract_and_store_strings){
    std::ifstream file ("../../Dec10/Dec10_test_input.txt");
    std::vector<std::string>strings;
    if (file.is_open()){
        strings = extract_and_store_strings(file);
        file.close();
    }
    ASSERT_EQ(strings[0], "[({(<(())[]>[[{[]{<()<>>");
}
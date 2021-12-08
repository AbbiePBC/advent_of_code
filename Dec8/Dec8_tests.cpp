//
// Created by Abbie Currington on 08/12/2021.
//
#include "gtest/gtest.h"
#include "Dec8_fns.h"

TEST(Dec8, test_extract_output){
    std::string input = "acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf";
    std::vector<std::string> output = extract_output(input);
    ASSERT_EQ(output[0],"cdfeb");
    ASSERT_EQ(output[3],"cdbaf");

}


TEST(Dec8, test_count_unique_num_segments){
    std::string input = "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe";
    std::vector<std::string> output = extract_output(input);
    ASSERT_EQ(count_unique_num_segments(output), 2)<<"expect 2.\n";
    std::string input1 = "edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc";
    std::vector<std::string> output2 = extract_output(input1);
    ASSERT_EQ(count_unique_num_segments(output2), 3);

}
//
// Created by Abbie Currington on 08/12/2021.
//
#include "gtest/gtest.h"
#include "Dec8_fns.h"




TEST(Dec8, test_extract_input_and_output){
    std::string input = "acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf";
    std::vector<std::string> input_digits;
    std::vector<std::string> output_digits;
    extract_strings(input, input_digits, output_digits);
    ASSERT_EQ(output_digits[0], "cdfeb");
    ASSERT_EQ(output_digits[3], "cdbaf");
    if (!part_one){
        ASSERT_EQ(input_digits[0], "acedgfb");
        ASSERT_EQ(input_digits[4], "dab");
        ASSERT_EQ(input_digits[9], "ab");
    }


}

TEST(Dec8, test_count_unique_num_segments){
    // hardcode this instead
    std::string input = "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe";
    std::vector<std::string> input_digits; // this one is pointless but allows same fn to be used for both parts
    std::vector<std::string> output_digits;
    extract_strings(input, input_digits, output_digits);
    ASSERT_EQ(count_unique_num_segments(output_digits), 2)<<"expect 2.\n";
    std::string input1 = "edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc";
    std::vector<std::string> input_digits2; // this one is pointless but allows same fn to be used for both parts
    std::vector<std::string> output_digits2;
    extract_strings(input1, input_digits2, output_digits2);
    ASSERT_EQ(count_unique_num_segments(output_digits2), 3);

}

TEST(Dec8, test_find_chars_for_1){
    std::vector<std::string> vec(2,"z");
    //initialise with char that is not possible to input
    vec[0] = "be";
    vec[1] = "abcd";
    std::vector<char> two_letter_vector;
    two_letter_vector = find_chars_for_1(vec[0]);
    ASSERT_EQ(two_letter_vector[0], 'b');
    ASSERT_EQ(two_letter_vector[1], 'e');
    std::vector<std::string> vec2(4,"z");
    std::vector<char> two_letter_vector2;
    vec2[0] = "fcgedb";
    vec2[1] = "cgb";
    vec2[2] = "dgebacf";
    vec2[3] = "gc";
    two_letter_vector2 = find_chars_for_1(vec2[3]);
    ASSERT_EQ(two_letter_vector2[0], 'g');
    ASSERT_EQ(two_letter_vector2[1], 'c');


}


TEST(Dec8, test_find_right_top){
    std::vector<std::string> vec = {"ed", "bcgafe", "cdgba", "cbgef"};
    std::vector<char> two_letter_vector = {'e', 'd'};
    char right_top = 'z';
    char right_bottom = 'z';
    std::vector<std::string> string_representations(10, "z");
    find_right_top(vec, two_letter_vector, right_top, right_bottom);
    ASSERT_EQ(right_top, 'd');
    ASSERT_EQ(right_bottom, 'e');

}
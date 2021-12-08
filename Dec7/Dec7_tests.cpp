//
// Created by Abbie Currington on 08/12/2021.
//
#include "gtest/gtest.h"
#include "Dec7_fns.h"

TEST(Dec7, test_store_displacements){
    std::string input = "16,1,2,0,4,2,7,1,2,14,";
    std::vector<int> displacement(max_displacement, 0);
    displacement = store_displacements(input);
    ASSERT_EQ(displacement[0],1);
    ASSERT_EQ(displacement[1],2);
    ASSERT_EQ(displacement[14],1);

}

TEST(Dec7, test_fuel_consumption_1){
    //TODO link tests to use the output of previous test in this one?
    std::string input = "16,1,2,0,4,2,7,1,2,14,";
    std::vector<int> displacement(max_displacement, 0);
    displacement = store_displacements(input);
    std::int64_t result = calc_fuel_consumption_part_1(displacement, 1);
    ASSERT_EQ(result, 41);
    result = calc_fuel_consumption_part_1(displacement, 10);
    ASSERT_EQ(result, 71);
    result = calc_fuel_consumption_part_1(displacement, 2);
    ASSERT_EQ(result, 37);
}

TEST(Dec7, test_fuel_consumption_2){
    std::string input = "16,1,2,0,4,2,7,1,2,14,";
    std::vector<int> displacement(max_displacement, 0);
    displacement = store_displacements(input);
    std::int64_t result = calc_fuel_consumption_part_2(displacement, 2);
    ASSERT_EQ(result, 206);
    result = calc_fuel_consumption_part_2(displacement, 5);
    ASSERT_EQ(result, 168);
}


TEST(Dec7, test_triangle_num){

    ASSERT_EQ(triangle_num(3), 6);
    ASSERT_EQ(triangle_num(2), 3);
}
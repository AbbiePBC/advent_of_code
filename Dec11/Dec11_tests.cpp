//
// Created by Abbie Currington on 15/12/2021.
//

#include "gtest/gtest.h"
#include "Dec11_fns.h"

#ifdef small_example
// remember to update row size in header!
TEST(Dec11, test_extract_and_store_strings){
    std::ifstream file ("../../Dec11/Dec11_test_input.txt");

    if (file.is_open()){
        int num_steps = 0;
//        Octopods octopods(file, num_steps);
//        ASSERT_EQ(octopods.grid[0][0], 1);
//        ASSERT_EQ(octopods.grid[2][3], 9);
//        ASSERT_EQ(octopods.grid[row_size - 1][row_size -1], 1);
        num_steps = 2;
        Octopods octopods2(file, num_steps);

        ASSERT_EQ(octopods2.grid[0][0], 4);
        ASSERT_EQ(octopods2.grid[2][3], 1);
        ASSERT_EQ(octopods2.grid[row_size - 1][row_size -1], 4);

        file.close();
    }
}

TEST(Dec11, test_flash_count){
    std::ifstream file ("../../Dec11/Dec11_test_input.txt");

    if (file.is_open()){
        int num_steps = 2;
        Octopods octopods(file, num_steps);
        ASSERT_EQ(octopods.num_flashes, 9);

        file.close();
    }
}

#endif

TEST(Dec11, test_flash_count){
    std::ifstream file ("../../Dec11/Dec11_big_test_input.txt");

    if (file.is_open()){
        int num_steps = 100;
        Octopods octopods(file, num_steps);
        ASSERT_EQ(octopods.num_flashes, 1656);

        file.close();
    }
}



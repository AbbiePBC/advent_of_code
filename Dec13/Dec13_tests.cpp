//
// Created by Abbie Currington on 22/12/2021.
//

#include "gtest/gtest.h"
#include "Dec13_fns.h"

TEST(Dec13, test_store_coords){
    std::ifstream file ("../../Dec13/test_input.txt");

    if (file.is_open()){
        AllCoords input(file);
        file.close();
        ASSERT_EQ(input.max_x, 10); // num columns
        ASSERT_EQ(input.max_y, 14); // num rows
        ASSERT_EQ(input.coords[0].x, 6);
        ASSERT_EQ(input.coords[0].y, 10);
        ASSERT_EQ(input.axes[0].x, 0);
        ASSERT_EQ(input.axes[0].y, 7);
        ASSERT_EQ(input.num_dots, 17);
    }
}
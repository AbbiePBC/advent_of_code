//
// Created by Abbie Currington on 15/12/2021.
//

#include "gtest/gtest.h"
#include "Dec9_fns.h"

TEST(Dec9, test_extract_and_store_input){
    std::ifstream file ("../../Dec9/Dec9_test_input.txt");
    std::vector<std::vector<int> >inputs;
    if (file.is_open()){
        inputs = extract_and_store_input(file);
        file.close();
    }

    ASSERT_EQ(inputs[0][0], 2);
    ASSERT_EQ(inputs[0][1], 1);
    ASSERT_EQ(inputs[1][0], 3);
    int num_basins = 1;
    std::vector<std::vector<int> > basin_grid = inputs;
    int sum_risk = find_risk_and_set_basins(inputs, basin_grid, num_basins);
    ASSERT_EQ(sum_risk, 15);
    std::vector<int> basin_size = fill_basins(basin_grid, num_basins);
    ASSERT_EQ(num_basins, 5);
    ASSERT_EQ(basin_size[0], 1);
    ASSERT_EQ(basin_size[1], 3);
    ASSERT_EQ(basin_size[2], 9);
    ASSERT_EQ(basin_size[3], 14);
    ASSERT_EQ(basin_size[4], 9);
    int part_two_result = find_max_basins(basin_size);
    ASSERT_EQ(part_two_result, (9*14*9));

}
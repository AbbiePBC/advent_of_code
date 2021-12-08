//
// Created by Abbie Currington on 08/12/2021.
//

#include "gtest/gtest.h"
#include "Dec6_fns.h"

TEST(Dec6, test_store_input){
//fish vector stores the number of fish with each number of days left

    std::vector<int> fish(max_days,0);
    std::string test_input = "1,2,3,1";
    int num_fish = store_input_count_fish(test_input, fish);
    ASSERT_EQ(fish[0],0);
    ASSERT_EQ(fish[1],2);
    ASSERT_EQ(fish[2],1);
    ASSERT_EQ(fish[3],1);
    ASSERT_EQ(num_fish, 4);
}

TEST(Dec6, test_update_fish){
    std::vector<int> fish (max_days, 0);
    fish[0] = 1;
    fish[1] = 2;
    fish[3] = 6;
    for (int i = 0 ; i < max_days; i++){
        std::cout <<"input " <<fish[i]<<std::endl;
    }
    int new_fish = update_fish(fish);
    ASSERT_EQ(fish[0],2);
    ASSERT_EQ(fish[3],0);
    ASSERT_EQ(fish[8],1);
    ASSERT_EQ(new_fish,1);
}
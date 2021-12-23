//
// Created by Abbie Currington on 23/12/2021.
//

#include "gtest/gtest.h"
#include "Dec14_fns.h"

TEST(Dec14, test_extract_polymer){
std::ifstream file ("../../Dec14/test_input.txt");

    if (file.is_open()){
        Polymer input(file);
//        ASSERT_EQ(input.head->el, 'B');
//        ASSERT_EQ(input.head->next->el, 'C');
//        ASSERT_EQ(input.head->next->next->next->next->el, 'Z');
        ASSERT_EQ(input.steps[0].element1, 'C');
        ASSERT_EQ(input.steps[0].element2, 'H');
        ASSERT_EQ(input.steps[0].insert, 'B');



        file.close();
    }
}
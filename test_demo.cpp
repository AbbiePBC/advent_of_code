
#include "gtest/gtest.h"

TEST(TestDemo, hello_test) {
    std::cout << "Hello test" << std::endl;
    ASSERT_EQUALS(2, 3) << "How come 2 is not the same as 3??";
}
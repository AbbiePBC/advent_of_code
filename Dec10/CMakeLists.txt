
cmake_minimum_required(VERSION 3.15)

project(AdventOfCodeDec10)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Now simply link against gtest or gtest_main as needed. Eg

add_executable(Dec10 Dec10.cpp Dec10_fns.cpp)
add_executable(Dec10_tests Dec10_tests.cpp Dec10_fns.cpp)
target_link_libraries(Dec10_tests gtest_main)
add_test(NAME test_10 COMMAND test_Dec10)


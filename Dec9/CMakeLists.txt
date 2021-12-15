cmake_minimum_required(VERSION 3.15)

project(AdventOfCodeDec9)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

add_executable(Dec9 Dec9.cpp Dec9_fns.cpp)
add_executable(Dec9_tests Dec9_tests.cpp Dec9_fns.cpp)
target_link_libraries(Dec9_tests gtest_main)
add_test(NAME test_9 COMMAND test_Dec9)
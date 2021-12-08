cmake_minimum_required(VERSION 3.15)

project(AdventOfCode)

add_executable(Dec1 Dec1.cpp)
add_executable(Dec2 Dec2.cpp)
add_executable(Dec3 Dec3.cpp)
add_executable(Dec4 Dec4.cpp)
add_executable(Dec4_part2 Dec4_part2.cpp)
add_executable(Dec5 Dec5.cpp)

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
add_executable(test_demo test_demo.cpp)
target_link_libraries(test_demo gtest_main)
add_test(NAME test_demo_test COMMAND test_demo)

# add_library(Dec6 Dec6_tests.cpp)
add_executable(Dec6 Dec6.cpp Dec6_fns.cpp)
add_executable(Dec6_tests Dec6_tests.cpp Dec6_fns.cpp)
#target_include_directories(Dec6_tests PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            "${PROJECT_SOURCE_DIR}")
target_link_libraries(Dec6_tests gtest_main)
add_test(NAME test_store_input COMMAND test_Dec6)

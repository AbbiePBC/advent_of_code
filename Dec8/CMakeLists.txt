cmake_minimum_required(VERSION 3.15)

project(AdventOfCodeDec8)

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

add_executable(Dec8 Dec8.cpp Dec8_fns.cpp)
add_executable(Dec8_tests Dec8_tests.cpp Dec8_fns.cpp)
target_link_libraries(Dec8_tests gtest_main)
add_test(NAME test_8 COMMAND test_Dec8)
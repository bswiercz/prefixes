cmake_minimum_required(VERSION 3.0)
project(prefixes)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        prefixes
        prefixes.c
)

add_executable(
        prefixes_test
        main_test.cc
)

target_link_libraries(
        prefixes_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(prefixes_test)

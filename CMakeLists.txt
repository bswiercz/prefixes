cmake_minimum_required(VERSION 3.0)
project(prefixes)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 11)

add_executable(
        prefixes
        main.c
        prefixes.c
)

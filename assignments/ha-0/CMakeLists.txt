cmake_minimum_required(VERSION 3.8)
project(ha-0 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES binarize.c test_binarize.c)
add_executable(ha-0 ${SOURCE_FILES})
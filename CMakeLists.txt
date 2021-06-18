cmake_minimum_required(VERSION 3.17)
project(external_sorting)

set(CMAKE_CXX_STANDARD 20)

add_executable(external_sorting main.cpp random_string_generator.h file_generator.h file_generator.cpp file_sort.h file_sort.cpp)
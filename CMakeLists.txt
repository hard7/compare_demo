cmake_minimum_required(VERSION 3.3)
project(compare_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(compare_demo ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.3)
project(uva10065)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10065.cpp)

add_executable(uva10065 ${SOURCE_FILES})
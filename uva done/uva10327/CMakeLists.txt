cmake_minimum_required(VERSION 3.3)
project(uva10327)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10327.cpp)

add_executable(uva10327 ${SOURCE_FILES})
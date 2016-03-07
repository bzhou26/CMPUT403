cmake_minimum_required(VERSION 3.3)
project(uva10034)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10034.cpp)

add_executable(uva10034 ${SOURCE_FILES})
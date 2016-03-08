cmake_minimum_required(VERSION 3.3)
project(uva10672)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10672.cpp)

add_executable(uva10672 ${SOURCE_FILES})
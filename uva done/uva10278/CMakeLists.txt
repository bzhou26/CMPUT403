cmake_minimum_required(VERSION 3.5)
project(uva10278)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10278.cpp)

add_executable(uva10278 ${SOURCE_FILES})
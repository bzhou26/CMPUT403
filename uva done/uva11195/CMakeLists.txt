cmake_minimum_required(VERSION 3.3)
project(uva11195)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva11195_bit.cpp)

add_executable(uva11195 ${SOURCE_FILES})
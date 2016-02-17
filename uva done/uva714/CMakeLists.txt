cmake_minimum_required(VERSION 3.3)
project(uva714)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_714_bi2.cpp)

add_executable(uva714 ${SOURCE_FILES})
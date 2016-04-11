cmake_minimum_required(VERSION 3.5)
project(uva701)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_701.cpp)

add_executable(uva701 ${SOURCE_FILES})
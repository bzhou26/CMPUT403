cmake_minimum_required(VERSION 3.5)
project(uva11827)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11827.cpp)

add_executable(uva11827 ${SOURCE_FILES})
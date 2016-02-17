cmake_minimum_required(VERSION 3.3)
project(uva11331)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11331.cpp)

add_executable(uva11331 ${SOURCE_FILES})
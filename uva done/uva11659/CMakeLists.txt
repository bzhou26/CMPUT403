cmake_minimum_required(VERSION 3.5)
project(uva11659)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11659.cpp)

add_executable(uva11659 ${SOURCE_FILES})
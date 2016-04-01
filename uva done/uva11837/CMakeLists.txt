cmake_minimum_required(VERSION 3.4)
project(uva11837)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11837.cpp)

add_executable(uva11837 ${SOURCE_FILES})
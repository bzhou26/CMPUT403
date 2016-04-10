cmake_minimum_required(VERSION 3.5)
project(uva11212)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11212.cpp)

add_executable(uva11212 ${SOURCE_FILES})
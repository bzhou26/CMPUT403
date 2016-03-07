cmake_minimum_required(VERSION 3.3)
project(uva11329)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11329.cpp)

add_executable(uva11329 ${SOURCE_FILES})
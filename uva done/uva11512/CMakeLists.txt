cmake_minimum_required(VERSION 3.4)
project(uva11512)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_11512.cpp)

add_executable(uva11512 ${SOURCE_FILES})
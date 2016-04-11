cmake_minimum_required(VERSION 3.5)
project(uva10014)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10014.cpp)

add_executable(uva10014 ${SOURCE_FILES})
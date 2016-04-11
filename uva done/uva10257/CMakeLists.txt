cmake_minimum_required(VERSION 3.5)
project(uva10257)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10257.cpp)

add_executable(uva10257 ${SOURCE_FILES})
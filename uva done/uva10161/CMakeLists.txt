cmake_minimum_required(VERSION 3.5)
project(uva10161)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10161.cpp)

add_executable(uva10161 ${SOURCE_FILES})
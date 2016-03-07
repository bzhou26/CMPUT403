cmake_minimum_required(VERSION 3.3)
project(uva303)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_303.cpp)

add_executable(uva303 ${SOURCE_FILES})
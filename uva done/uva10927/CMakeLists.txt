cmake_minimum_required(VERSION 3.5)
project(uva10927)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_10927.cpp)

add_executable(uva10927 ${SOURCE_FILES})
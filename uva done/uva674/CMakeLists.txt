cmake_minimum_required(VERSION 3.4)
project(uva674)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_674.cpp)

add_executable(uva674 ${SOURCE_FILES})
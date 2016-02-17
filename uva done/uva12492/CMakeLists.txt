cmake_minimum_required(VERSION 3.3)
project(uva12492)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_12492.cpp)

add_executable(uva12492 ${SOURCE_FILES})
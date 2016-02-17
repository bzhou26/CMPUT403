cmake_minimum_required(VERSION 3.3)
project(contest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    a.cpp)

add_executable(contest ${SOURCE_FILES})
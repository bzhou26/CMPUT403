cmake_minimum_required(VERSION 3.3)
project(uva202)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva202.c)

add_executable(uva202 ${SOURCE_FILES})
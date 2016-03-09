cmake_minimum_required(VERSION 3.3)
project(uva374)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    uva_374.cpp)

add_executable(uva374 ${SOURCE_FILES})
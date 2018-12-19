cmake_minimum_required(VERSION 3.6)
project(Task5_4)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Task5_4 ${SOURCE_FILES})
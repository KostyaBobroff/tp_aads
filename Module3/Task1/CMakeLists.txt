cmake_minimum_required(VERSION 3.12)
project(Task1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task1 main.cpp CListGraph.cpp CListGraph.h IGraph.cpp IGraph.h CMatrixGraph.cpp CMatrixGraph.h CSetGraph.cpp CSetGraph.h CArcGraph.cpp CArcGraph.h)
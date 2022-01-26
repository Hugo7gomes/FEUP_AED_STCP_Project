cmake_minimum_required(VERSION 3.20)
project(ProjectSTCP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectSTCP main.cpp src/graph.cpp src/graph.h src/minHeap.h src/readFiles.cpp src/readFiles.cpp src/readFiles.h src/node.cpp src/node.h)

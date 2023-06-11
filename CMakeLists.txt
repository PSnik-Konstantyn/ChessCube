cmake_minimum_required(VERSION 3.25)
project(ChessCube)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessCube chess_cube.cpp chess_cube.h cube.cpp cube.h main.cpp)

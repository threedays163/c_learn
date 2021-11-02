cmake_minimum_required(VERSION 3.20)
project(c_learn)

set(CMAKE_CXX_STANDARD 11)

add_executable(c_learn c++/main.cpp c/c_main.h c/c_main.c c/struct/StructTest.c c/struct/StructTest.h)

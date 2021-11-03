cmake_minimum_required(VERSION 3.17.3)
project(c_learn)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_FLAGS -m32)
#set(CMAKE_CXX_FLAGS -m32)

add_executable(c_learn c++/main.cpp c/c_main.h c/c_main.c c/struct/StructTest.c c/struct/StructTest.h c/print/printTest.h c/print/printTest.c c/fun/fun.c c/fun/fun.h c/pointer/pointer.c c/pointer/pointer.h c/asm/asm.c c/asm/asm.h c/mem_seek/mem_seek.c c/mem_seek/mem_seek.h)

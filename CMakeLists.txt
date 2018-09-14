cmake_minimum_required(VERSION 3.12)
project(CTLib)

set(CMAKE_CXX_STANDARD 17)

add_executable(CTLib main.cpp _HeaderCore.h CT_tuple.h)
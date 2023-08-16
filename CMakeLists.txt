cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp Lifeguard.cpp Lifeguard.h)
add_library(lib library.cpp)

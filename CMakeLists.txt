cmake_minimum_required(VERSION 3.21)
project(Lifeguard-App)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp Lifeguard.cpp Lifeguard.h)
add_library(lib library.cpp clockthread.cpp)

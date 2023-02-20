cmake_minimum_required(VERSION 3.17)

project(DrawGraphical)

set(CMAKE_CXX_STANDARD 11)

link_libraries(SDL2)

add_executable(DrawGraphical main.cpp)

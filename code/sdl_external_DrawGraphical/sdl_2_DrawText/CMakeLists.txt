cmake_minimum_required(VERSION 3.17)

project(DrawText)

set(CMAKE_CXX_STANDARD 11)

link_libraries(SDL2 SDL2_image SDL2_ttf)

add_executable(DrawText main.cpp)

cmake_minimum_required(VERSION 3.7)
project(rougelike)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ncurses)
set(SOURCE_FILES main.cpp game_objects Graphics.cpp Graphics.h)
add_executable(rougelike ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.7)
project(rougelike)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ncurses)
file(GLOB gameobjsrc RELATIVE "game_objects" "*.cpp")
file(GLOB gameobjsrc RELATIVE "game_objects" "*.h")
file(GLOB dungeonsrc RELATIVE "dungeon" "*.cpp")

set(SOURCE_FILES main.cpp ${gameobjsrc} ${dungeonsrc})
add_executable(rougelike ${SOURCE_FILES})
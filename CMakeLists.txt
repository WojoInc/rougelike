cmake_minimum_required(VERSION 3.7)
project(rougelike)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ncurses)
file(GLOB gameobjsrc RELATIVE "game_objects" "*.cpp")
file(GLOB gameobjsrc RELATIVE "game_objects" "*.h")
file(GLOB dungeonsrc RELATIVE "dungeon" "*.cpp")

#[[set(TESTNC demo.cc)
add_executable(testnc ${TESTNC})]]
set(SOURCE_FILES main.cpp ${gameobjsrc} ${dungeonsrc} main.h RougeLike.cpp RougeLike.h PC.cpp PC.h Floor.cpp Floor.h Cell.cpp Cell.h Character.cpp Character.h Coordinate.cpp Coordinate.h)
add_executable(rougelike ${SOURCE_FILES})
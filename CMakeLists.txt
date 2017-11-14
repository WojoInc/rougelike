cmake_minimum_required(VERSION 3.7)
project(rougelike)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ncurses)
file(GLOB gameobjsrc RELATIVE "game_objects" "*.cpp")
file(GLOB gameobjsrc RELATIVE "game_objects" "*.h")
file(GLOB dungeonsrc RELATIVE "dungeon" "*.cpp")

set(SOURCE_FILES src/main.cpp ${gameobjsrc} ${dungeonsrc} include/main.h src/RougeLike.cpp include/RougeLike.h src/PC.cpp include/PC.h src/Floor.cpp include/Floor.h include/stdef.h src/Cell.cpp include/Cell.h)
add_executable(rougelike ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.7)
project(rougelike)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ncurses)
set(SOURCE_FILES src/main.cpp include/main.h src/RougeLike.cpp include/RougeLike.h src/PC.cpp include/PC.h src/Floor.cpp include/Floor.h include/stdef.h src/Cell.cpp include/Cell.h include/Drawable.cpp include/Drawable.h)
add_executable(rougelike ${SOURCE_FILES})
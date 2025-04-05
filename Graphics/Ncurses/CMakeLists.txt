cmake_minimum_required(VERSION 3.10)
project(arcade_ncurses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)
file(GLOB SOURCES src/*.cpp)

add_library(arcade_ncurses SHARED ${SOURCES})
set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

target_include_directories(arcade_ncurses PRIVATE
    ../
    ../../modules/anal/include/ANAL/
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(arcade_ncurses PRIVATE
    ${CURSES_LIBRARIES}
)

target_compile_options(arcade_ncurses PRIVATE -fno-gnu-unique)

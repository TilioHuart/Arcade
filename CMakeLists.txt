cmake_minimum_required(VERSION 3.10)

project(Arcade CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(modules/anal)

# Games
add_subdirectory(Games/Pacman)
add_subdirectory(Games/Minesweeper)

# Displays
add_subdirectory(Graphics/Ncurses)
add_subdirectory(Graphics/OpenGl)
add_subdirectory(Graphics/SDL)

# Core
add_subdirectory(Arcade/)

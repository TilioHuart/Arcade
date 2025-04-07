cmake_minimum_required(VERSION 3.10)

project(Arcade CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(modules/anal)

# Games
# add_subdirectory(Games/Pacman)
add_subdirectory(Games/Minesweeper)

# Displays
add_subdirectory(Graphics/Ncurses)
add_subdirectory(Graphics/OpenGl)
add_subdirectory(Graphics/SDL)
add_subdirectory(Graphics/SFML)

# Core
add_subdirectory(Arcade/)

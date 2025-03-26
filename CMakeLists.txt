cmake_minimum_required(VERSION 3.10)

project(Arcade CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Games
add_subdirectory(Games/Pacman)

# Displays
add_subdirectory(Graphics/Ncurses)
add_subdirectory(Graphics/OpenGl)

# Core
add_subdirectory(Arcade/)

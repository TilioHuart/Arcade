cmake_minimum_required(VERSION 3.10)

project(Arcade CXX)

# Games
add_subdirectory(Games/Pacman)

# Displays
add_subdirectory(Graphics/Ncurses)

# Core
add_subdirectory(Arcade/)

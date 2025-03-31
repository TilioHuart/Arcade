cmake_minimum_required(VERSION 3.10)
project(arcade_minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(arcade_minesweeper SHARED ${SOURCES})
set_target_properties(arcade_minesweeper PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(arcade_minesweeper PRIVATE -fno-gnu-unique)


cmake_minimum_required(VERSION 3.10)
project(DisplayNcurses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(DisplayNcurses SHARED ${SOURCES})

target_compile_options(DisplayNcurses PRIVATE -fno-gnu-unique)

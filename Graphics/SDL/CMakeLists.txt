cmake_minimum_required(VERSION 3.10)
project(SDLRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(SDLRenderer SHARED ${SOURCES})

target_compile_options(SDLRenderer PRIVATE -fno-gnu-unique)

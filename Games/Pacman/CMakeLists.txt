cmake_minimum_required(VERSION 3.10)
project(GamePacman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(GamePacman SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_compile_options(GamePacman PRIVATE -fno-gnu-unique)

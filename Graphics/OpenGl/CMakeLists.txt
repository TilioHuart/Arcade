cmake_minimum_required(VERSION 3.10)
project(DisplayOpenGl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(DisplayOpenGl SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(DisplayOpenGl PRIVATE -fno-gnu-unique)

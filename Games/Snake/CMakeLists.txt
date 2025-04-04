cmake_minimum_required(VERSION 3.10)
project(arcade_snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(arcade_snake SHARED ${SOURCES})
set_target_properties(arcade_snake PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(arcade_snake PRIVATE -fno-gnu-unique)


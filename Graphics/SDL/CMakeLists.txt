cmake_minimum_required(VERSION 3.10)
project(SDLRenderer LANGUAGES CXX)

find_package(SDL2 REQUIRED)

file(GLOB SOURCES src/*.cpp)
add_library(SDLRenderer SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)

target_compile_options(SDLRenderer PRIVATE -fno-gnu-unique)

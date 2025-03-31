cmake_minimum_required(VERSION 3.10)
project(DisplaySDL2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(DisplaySDL2 SHARED ${SOURCES})

find_package(SDL2)
find_package(SDL2_image)

if (SDL2_FOUND AND SDL2_IMAGE_FOUND)
    add_definitions(-DUSE_SDL2)
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(DisplaySDL2 PRIVATE -fno-gnu-unique)

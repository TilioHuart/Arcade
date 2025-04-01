cmake_minimum_required(VERSION 3.10)
project(arcade_sdl2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(arcade_sdl2 SHARED ${SOURCES})
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

if (SDL2_FOUND AND SDL2_IMAGE_FOUND AND SDL2_TTF_FOUND)
    add_definitions(-DUSE_SDL2)
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS} ${SDL2_TTF_LIBRARY_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(arcade_sdl2 PRIVATE -fno-gnu-unique)

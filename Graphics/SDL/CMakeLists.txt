cmake_minimum_required(VERSION 3.10)
project(arcade_sdl2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig)
pkg_check_modules(SDL2 sdl2)
pkg_check_modules(SDL2_IMAGE SDL2_image)
pkg_check_modules(SDL2_TTF SDL2_ttf)

set(MISSING_DEP FALSE)
if (NOT SDL2_FOUND OR NOT SDL2_IMAGE_FOUND OR NOT SDL2_TTF_FOUND)
    set(MISSING_DEP TRUE)
endif()

if (MISSING_DEP)
    file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")
    set(SOURCES ${CMAKE_BINARY_DIR}/empty.cpp)
else()
    file(GLOB SOURCES src/*.cpp)
endif()

add_library(arcade_sdl2 SHARED ${SOURCES})
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

target_include_directories(arcade_sdl2 PRIVATE
    ../
    ../../modules/anal/include/ANAL/
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(arcade_sdl2 PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)

target_compile_options(arcade_sdl2 PRIVATE -fno-gnu-unique)

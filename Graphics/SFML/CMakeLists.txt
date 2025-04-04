cmake_minimum_required(VERSION 3.10)
project(arcade_sfml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2 COMPONENTS graphics window system)

set(MISSING_DEP FALSE)
if (NOT SFML_FOUND)
    set(MISSING_DEP TRUE)
endif()

if (MISSING_DEP)
    file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")
    set(SOURCES ${CMAKE_BINARY_DIR}/empty.cpp)
else()
    file(GLOB SOURCES src/*.cpp)
endif()

add_library(arcade_sfml SHARED ${SOURCES})
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

target_include_directories(arcade_sfml PRIVATE
    ../
    ../../modules/anal/include/ANAL/
)

target_link_libraries(arcade_sfml PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

target_compile_options(arcade_sfml PRIVATE -fno-gnu-unique)

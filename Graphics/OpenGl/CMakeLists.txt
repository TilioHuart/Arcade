cmake_minimum_required(VERSION 3.10)
project(arcade_opengl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(arcade_opengl SHARED ${SOURCES})
set_target_properties(arcade_opengl PROPERTIES PREFIX "")

find_package(OpenGL)
find_package(GLEW)

if (OPENGL_FOUND AND GLEW_FOUND)
    add_definitions(-DUSE_OPENGL)
    include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(arcade_opengl PRIVATE -fno-gnu-unique)

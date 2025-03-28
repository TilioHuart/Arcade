cmake_minimum_required(VERSION 3.10)
project(DisplayOpenGl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(DisplayOpenGl SHARED ${SOURCES})

find_package(OpenGL)
find_package(GLEW)

if (OPENGL_FOUND AND GLEW_FOUND)
    add_definitions(-DUSE_OPENGL)
    include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ../)
target_include_directories(${PROJECT_NAME} PRIVATE ../../modules/anal/include/ANAL)
target_compile_options(DisplayOpenGl PRIVATE -fno-gnu-unique)

cmake_minimum_required(VERSION 3.10)

project(arcade CXX)

set(SOURCE_FILES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

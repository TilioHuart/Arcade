cmake_minimum_required(VERSION 3.10)

project(arcade CXX)

set(SOURCE_FILES
    src/main.cpp
    src/Arcade.cpp
    src/DlUtils.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ../modules/anal/include/ANAL)
target_include_directories(${PROJECT_NAME} PRIVATE ../Games/)
target_include_directories(${PROJECT_NAME} PRIVATE ../Graphics/)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

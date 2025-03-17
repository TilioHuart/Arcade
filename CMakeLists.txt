cmake_minimum_required(VERSION 3.10)

project(nanotekspice CXX)

set(SOURCE_FILES
    src/main.cpp

    # services
    src/services/Services.cpp

    # parsing
    src/parsing/Parsing.cpp

    # components
        src/components/IComponent.cpp
        src/components/AComponent.cpp
        src/components/ComponentFactory.cpp
        src/components/InputPin.cpp

        # special
        src/components/specialComponents/InputComponent.cpp
        src/components/specialComponents/OutputComponent.cpp
        src/components/specialComponents/TrueComponent.cpp
        src/components/specialComponents/FalseComponent.cpp
        src/components/specialComponents/ClockComponent.cpp

        # elementary
        src/components/elementaryComponents/AndComponent.cpp
        src/components/elementaryComponents/OrComponent.cpp
        src/components/elementaryComponents/XorComponent.cpp
        src/components/elementaryComponents/NotComponent.cpp

        # gates
        src/components/gates/4001_NorGate.cpp
        src/components/gates/4011_NandGate.cpp
        src/components/gates/4030_XorGate.cpp
        src/components/gates/4069_NotGate.cpp
        src/components/gates/4071_OrGate.cpp
        src/components/gates/4081_AndGate.cpp
        # advanced

)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

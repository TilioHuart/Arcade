//
// EPITECH PROJECT, 2025
// OpenGl base functions
// File description:
// OpenGl base functions
//

#ifdef USE_OPENGL

#include "IModule.hpp"
#include "OpenGl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

ANAL::OpenGlRenderer::OpenGlRenderer()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (glfwInit() == GLFW_FALSE) {
        std::cerr << "Error while initializing opengl window" << std::endl; // replace by throw
        return;
    }

    this->_window = glfwCreateWindow(this->_windowWidth, this->_windowHeight,
        this->_windowTitle.c_str(), nullptr, nullptr);
    if (this->_window == nullptr) {
        std::cerr << "Error while creating window" << std::endl; // replace by throw
        return;
    }
    glfwMakeContextCurrent(this->_window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error while initialising glew" << std::endl; // replace by throw
        return;
    }
}

ANAL::OpenGlRenderer::~OpenGlRenderer()
{
    if (this->_window != nullptr)
        glfwDestroyWindow(this->_window);
    glfwTerminate();
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::RENDERER;
}

std::unique_ptr<ANAL::IRenderer> uwu_entrypoint_renderer(void)
{
    return std::make_unique<ANAL::OpenGlRenderer>();
}
}

#endif

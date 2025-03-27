//
// EPITECH PROJECT, 2025
// OpenGl base functions
// File description:
// OpenGl base functions
//

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

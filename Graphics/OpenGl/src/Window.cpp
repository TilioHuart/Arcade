//
// EPITECH PROJECT, 2025
// Window
// File description:
// Window
//

#ifdef USE_OPENGL

#include "OpenGl.hpp"

void ANAL::OpenGlRenderer::setWindowTitle(const std::string &title) {}

void ANAL::OpenGlRenderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    this->_displayWindow();
}

void ANAL::OpenGlRenderer::render()
{
    this->_displayWindow();
}

void ANAL::OpenGlRenderer::_displayWindow()
{
    glfwSwapBuffers(this->_window);
}

#endif

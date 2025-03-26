//
// EPITECH PROJECT, 2025
// Draw OpenGl
// File description:
// Draw OpenGl
//

#include "IEntity.hpp"
#include "OpenGl.hpp"
#include <GL/gl.h>
#include <memory>

void ANAL::OpenGlRenderer::drawEntity(const ANAL::IEntity &entity)
{
}

void ANAL::OpenGlRenderer::drawText(
    const std::string &text, Vector2<int> position)
{}

void ANAL::OpenGlRenderer::setWindowTitle(const std::string &title) {}

std::vector<ANAL::Event> &ANAL::OpenGlRenderer::getEvents() 
{
    return this->_events;
}

void ANAL::OpenGlRenderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    this->_displayWindow();
}

void ANAL::OpenGlRenderer::render()
{
    while (!this->_entities.empty()) {
        auto &entity = this->_entities.back();
        this->_entities.pop();
    }
    this->_displayWindow();
}

void ANAL::OpenGlRenderer::_displayWindow()
{
    glfwSwapBuffers(this->_window);
}

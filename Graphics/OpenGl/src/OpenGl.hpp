//
// EPITECH PROJECT, 2025
// OpenGl
// File description:
// OpenGl
//

#pragma once

#include "ARenderer.hpp"
#include "Events.hpp"
#include "IEntity.hpp"
#include "ISprite.hpp"
#include "Vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <queue>
#include <vector>

namespace ANAL {
    class OpenGlRenderer : public ARenderer {
       public:
        OpenGlRenderer();

        ~OpenGlRenderer() override;

        void drawEntity(const IEntity &entity) override;

        void drawText(const std::string &text, Vector2<int> position) override;

        void setWindowTitle(const std::string &title) override;

        void render() override;

        std::vector<Event> &getEvents() override;

        void clear() override;

       private:
        GLFWwindow *_window = nullptr;
        GLuint _shaderProgram;
        GLuint _vertexShader;
        GLuint _fragmentShader;
        std::queue<IEntity> _entities;
        std::vector<Event> _events;

        void _displayWindow();
        void _loadShaders();
        GLuint _compileShader(GLenum type, const std::string &shaderCode);
        void _linkShaders();
        std::string _getFileData(const std::string &file) const;
    };
}  // namespace ANAL

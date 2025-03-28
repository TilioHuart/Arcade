//
// EPITECH PROJECT, 2025
// Shaders
// File description:
// Shaders
//

#ifdef USE_OPENGL

#include "OpenGl.hpp"
#include <GL/gl.h>
#include <fstream>
#include <iostream>
#include <sstream>

void ANAL::OpenGlRenderer::_loadShaders()
{
    std::string vertexCode = this->_getFileData("vertex_shader.glsl");
    std::string fragmentCode = this->_getFileData("fragment_shader.glsl");

    this->_vertexShader = this->_compileShader(GL_VERTEX_SHADER, vertexCode);
    this->_fragmentShader =
        this->_compileShader(GL_FRAGMENT_SHADER, fragmentCode);

    this->_linkShaders();

    glDeleteShader(this->_vertexShader);
    glDeleteShader(this->_fragmentShader);
}

GLuint ANAL::OpenGlRenderer::_compileShader(
    GLenum type, const std::string &shaderCode)
{
    GLuint shader = 0;
    GLint success = 0;
    const char *source = shaderCode.c_str();

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == 0) {
        std::cerr << "Unable to compile shader for type: " << type
                  << std::endl;  //replace by throw
        return 0;
    }
    return shader;
}

void ANAL::OpenGlRenderer::_linkShaders()
{
    GLint success = 0;
    this->_shaderProgram = glCreateProgram();

    glAttachShader(this->_shaderProgram, this->_vertexShader);
    glAttachShader(this->_shaderProgram, this->_fragmentShader);
    glLinkProgram(this->_shaderProgram);
    glGetProgramiv(this->_shaderProgram, GL_LINK_STATUS, &success);

    if (success == 0) {
        std::cerr << "Unable to link shaders"
                  << std::endl;  // replace by throw
    }
}

std::string ANAL::OpenGlRenderer::_getFileData(const std::string &file) const
{
    std::ifstream shaderFile(file);
    std::stringstream shaderStream;
    std::string shaderCode;

    if (!shaderFile.is_open()) {
        std::cerr << "Unable to open shader file:" << file
                  << std::endl;  // replace by throw
        return "";
    }
    shaderStream << shaderFile.rdbuf();
    shaderCode = shaderStream.str();
    shaderFile.close();
    return shaderCode;
}

#endif

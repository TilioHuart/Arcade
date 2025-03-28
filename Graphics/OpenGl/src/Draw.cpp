//
// EPITECH PROJECT, 2025
// Draw OpenGl
// File description:
// Draw OpenGl
//

#ifdef USE_OPENGL

#include "IEntity.hpp"
#include "OpenGl.hpp"
#include <GL/gl.h>
#include <array>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

void ANAL::OpenGlRenderer::drawEntity(const ANAL::IEntity &entity)
{
    std::string pathToImg = entity.getAsset().getTexturePath();
    int width = 0;
    int height = 0;
    int nbChannels = 0;

    unsigned char *imgData =
        stbi_load(pathToImg.c_str(), &width, &height, &nbChannels, 0);
    if (imgData == nullptr) {
        std::cerr << "Error while loading image" << std::endl;
        return;
    }

    GLuint texture = 0;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLenum format = (nbChannels == 4) ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
        GL_UNSIGNED_BYTE, imgData);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(imgData);

    std::array<float, 24> vertices = {//first triangle
        -1.0, 1.0, 0.0, 1.0, -1.0, -1.0, 0.0, 0.0, 1.0, -1.0, 1.0, 0.0,
        //second triangle
        -1.0, 1.0, 0.0, 1.0, 1.0, -1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0};

    GLuint VAO = 0;
    GLuint VBO = 0;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(
        0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
        (void *)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->_loadShaders();
    if (this->_shaderProgram == 0) {
        std::cerr << "Error while loading shaders" << std::endl; // replace by throw
        return;
    }
    glUseProgram(this->_shaderProgram);

    glUniform1i(glGetUniformLocation(this->_shaderProgram, "texture1"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
    glUseProgram(0);
}

void ANAL::OpenGlRenderer::drawText(
    const std::string &text, Vector2<int> position)
{}

#endif

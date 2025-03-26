//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SDLRenderer.cpp
//

#include "SDLRenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <ostream>

ANAL::SDLRenderer::SDLRenderer()
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = SDL_WINDOW_SHOWN;
    this->_windowHeight = 900;
    this->_windowWidth = 900;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "ERROR\n";
    this->_window = SDL_CreateWindow(this->_windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_windowWidth,
        this->_windowHeight, windowFlags);
    if (this->_window == nullptr)
        std::cout << "ERROR\n";
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    this->_renderer = SDL_CreateRenderer(this->_window, -1, rendererFlags);
    if (this->_renderer == nullptr)
        std::cout << "ERROR\n";
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

ANAL::SDLRenderer::~SDLRenderer()
{
    if (this->_renderer != nullptr)
        SDL_DestroyRenderer(this->_renderer);
    if (this->_window != nullptr)
        SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void ANAL::SDLRenderer::drawEntity(const ANAL::IEntity &entity) {}

void ANAL::SDLRenderer::drawText(
    const std::string &str, ANAL::Vector2<int> pos)
{}

void ANAL::SDLRenderer::setWindowTitle(const std::string &windowTitle) {}

void ANAL::SDLRenderer::render()
{
    SDL_RenderPresent(this->_renderer);
}

std::vector<ANAL::Event> &ANAL::SDLRenderer::getEvents()
{
}

void ANAL::SDLRenderer::clear()
{
    SDL_RenderClear(this->_renderer);
}

extern "C" {
ANAL::SDLRenderer *create_renderer()
{
    return new ANAL::SDLRenderer();
}

void destroy_renderer(ANAL::SDLRenderer *renderer)
{
    delete renderer;
}
}

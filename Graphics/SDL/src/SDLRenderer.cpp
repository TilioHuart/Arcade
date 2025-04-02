//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SDLRenderer.cpp
//

#include "IModule.hpp"
#include <map>

#    include "Events.hpp"
#    include "SDLRenderer.hpp"
#    include <SDL2/SDL.h>
#    include <SDL2/SDL_events.h>
#    include <SDL2/SDL_image.h>
#    include <SDL2/SDL_keycode.h>
#    include <SDL2/SDL_rect.h>
#    include <SDL2/SDL_render.h>
#    include <SDL2/SDL_ttf.h>
#    include <SDL2/SDL_video.h>
#    include <vector>

ANAL::SDLRenderer::SDLRenderer()
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = SDL_WINDOW_SHOWN;
    this->_windowHeight = 900;
    this->_windowWidth = 900;
    this->_sdlEvents = {};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Exception();
    this->_window = SDL_CreateWindow(this->_windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_windowWidth,
        this->_windowHeight, windowFlags);
    if (this->_window == nullptr)
        throw Exception();
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    this->_renderer = SDL_CreateRenderer(this->_window, -1, rendererFlags);
    if (this->_renderer == nullptr)
        throw Exception();
    if (TTF_Init() < 0)
        throw Exception();
    this->font = TTF_OpenFont("./JetBrainsMonoNerdFont-Medium.ttf", 25);
}

ANAL::SDLRenderer::~SDLRenderer()
{
    if (this->_renderer != nullptr)
        SDL_DestroyRenderer(this->_renderer);
    if (this->_window != nullptr)
        SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void ANAL::SDLRenderer::drawEntity(const ANAL::IEntity &entity)
{
    SDL_Texture *texture;
    SDL_Rect dest;

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    if (entity.getAsset().getTexturePath().empty())
        return;
    texture = IMG_LoadTexture(
        this->_renderer, entity.getAsset().getTexturePath().c_str());
    if (texture == nullptr)
        throw Exception();
    dest.x = entity.getPos().x;
    dest.y = entity.getPos().y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    SDL_RenderCopy(this->_renderer, texture, nullptr, &dest);
    SDL_DestroyTexture(texture);
}

void ANAL::SDLRenderer::drawText(
    const std::string &str, ANAL::Vector2<int> pos)
{
    SDL_Color White = {255, 255, 255};
    SDL_Surface *surface =
        TTF_RenderText_Solid(this->font, str.c_str(), White);
    SDL_Texture *Message =
        SDL_CreateTextureFromSurface(this->_renderer, surface);

    SDL_Rect rect;
    rect.x = pos.x;
    rect.y = pos.y;
    SDL_RenderCopy(this->_renderer, Message, nullptr, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(Message);
}

void ANAL::SDLRenderer::setWindowTitle(const std::string &windowTitle)
{
    this->_windowTitle = windowTitle;
}

void ANAL::SDLRenderer::render()
{
    SDL_RenderPresent(this->_renderer);
}

std::vector<ANAL::Event> &ANAL::SDLRenderer::getEvents()
{
    /*SDL_Event sdlEvent;*/
    /*const std::map<ANAL::Event, SDL_KeyCode> code{*/
    /*    {Event::PRESSED_KEY_A, SDLK_a}, {Event::PRESSED_KEY_B, SDLK_b},*/
    /*    {Event::PRESSED_KEY_C, SDLK_c}, {Event::PRESSED_KEY_D, SDLK_d},*/
    /*    {Event::PRESSED_KEY_E, SDLK_e}, {Event::PRESSED_KEY_F, SDLK_f},*/
    /*    {Event::PRESSED_KEY_G, SDLK_g}, {Event::PRESSED_KEY_H, SDLK_h},*/
    /*    {Event::PRESSED_KEY_I, SDLK_i}, {Event::PRESSED_KEY_J, SDLK_j},*/
    /*    {Event::PRESSED_KEY_K, SDLK_k}, {Event::PRESSED_KEY_L, SDLK_l},*/
    /*    {Event::PRESSED_KEY_M, SDLK_m}, {Event::PRESSED_KEY_N, SDLK_n},*/
    /*    {Event::PRESSED_KEY_O, SDLK_o}, {Event::PRESSED_KEY_P, SDLK_p},*/
    /*    {Event::PRESSED_KEY_Q, SDLK_q}, {Event::PRESSED_KEY_R, SDLK_r},*/
    /*    {Event::PRESSED_KEY_S, SDLK_s}, {Event::PRESSED_KEY_T, SDLK_t},*/
    /*    {Event::PRESSED_KEY_U, SDLK_u}, {Event::PRESSED_KEY_V, SDLK_v},*/
    /*    {Event::PRESSED_KEY_W, SDLK_w}, {Event::PRESSED_KEY_X, SDLK_x},*/
    /*    {Event::PRESSED_KEY_Y, SDLK_y}, {Event::PRESSED_KEY_Z, SDLK_z},*/
    /*    {Event::PRESSED_KEY_0, SDLK_0}, {Event::PRESSED_KEY_1, SDLK_1},*/
    /*    {Event::PRESSED_KEY_2, SDLK_2}, {Event::PRESSED_KEY_3, SDLK_3},*/
    /*    {Event::PRESSED_KEY_4, SDLK_4}, {Event::PRESSED_KEY_5, SDLK_5},*/
    /*    {Event::PRESSED_KEY_6, SDLK_6}, {Event::PRESSED_KEY_7, SDLK_7},*/
    /*    {Event::PRESSED_KEY_8, SDLK_8}, {Event::PRESSED_KEY_9, SDLK_9},*/
    /*    {Event::PRESSED_KEY_ARROW_RIGHT, SDLK_RIGHT},*/
    /*    {Event::PRESSED_KEY_ARROW_LEFT, SDLK_LEFT},*/
    /*    {Event::PRESSED_KEY_ARROW_UP, SDLK_UP},*/
    /*    {Event::PRESSED_KEY_ARROW_DOWN, SDLK_DOWN}};*/
    /**/
    /*while (SDL_PollEvent(&sdlEvent)) {*/
    /*    switch (sdlEvent.type) {*/
    /*        case SDL_KEYDOWN:*/
    /*            for (auto it : code)*/
    /*                if (sdlEvent.key.keysym.sym == it.second)*/
    /*                    this->_sdlEvents.push_back(it.first);*/
    /*        case SDL_QUIT:*/
    /*            this->_sdlEvents.push_back(Event::CLOSE);*/
    /*        default:*/
    /*            break;*/
    /*    }*/
    /*}*/
    /*return this->_sdlEvents;*/
}

void ANAL::SDLRenderer::clear()
{
    SDL_RenderClear(this->_renderer);
}


extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::RENDERER;
}
std::unique_ptr<ANAL::IRenderer> uwu_entrypoint_renderer(void)
{
    return std::make_unique<ANAL::SDLRenderer>();
}
}


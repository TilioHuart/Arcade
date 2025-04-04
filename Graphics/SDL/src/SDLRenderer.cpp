//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SDLRenderer.cpp
//

#include "IModule.hpp"
#include <map>

#include "Events.hpp"
#include "SDLRenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <vector>

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
    this->font =
        TTF_OpenFont("./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf", 25);
    if (this->font == nullptr)
        throw Exception();
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
    float cellSize = 900.0F / 32.0F;
    rect.x = static_cast<int>(pos.x * cellSize);
    rect.y = static_cast<int>(pos.y * cellSize);
    rect.w = surface->w;
    rect.h = surface->h;
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
    SDL_Event sdlEvent;
    const std::map<ANAL::Keys, SDL_KeyCode> code{{Keys::KEY_A, SDLK_a},
        {Keys::KEY_B, SDLK_b}, {Keys::KEY_C, SDLK_c}, {Keys::KEY_D, SDLK_d},
        {Keys::KEY_E, SDLK_e}, {Keys::KEY_F, SDLK_f}, {Keys::KEY_G, SDLK_g},
        {Keys::KEY_H, SDLK_h}, {Keys::KEY_I, SDLK_i}, {Keys::KEY_J, SDLK_j},
        {Keys::KEY_K, SDLK_k}, {Keys::KEY_L, SDLK_l}, {Keys::KEY_M, SDLK_m},
        {Keys::KEY_N, SDLK_n}, {Keys::KEY_O, SDLK_o}, {Keys::KEY_P, SDLK_p},
        {Keys::KEY_Q, SDLK_q}, {Keys::KEY_R, SDLK_r}, {Keys::KEY_S, SDLK_s},
        {Keys::KEY_T, SDLK_t}, {Keys::KEY_U, SDLK_u}, {Keys::KEY_V, SDLK_v},
        {Keys::KEY_W, SDLK_w}, {Keys::KEY_X, SDLK_x}, {Keys::KEY_Y, SDLK_y},
        {Keys::KEY_Z, SDLK_z}, {Keys::KEY_0, SDLK_0}, {Keys::KEY_1, SDLK_1},
        {Keys::KEY_2, SDLK_2}, {Keys::KEY_3, SDLK_3}, {Keys::KEY_4, SDLK_4},
        {Keys::KEY_5, SDLK_5}, {Keys::KEY_6, SDLK_6}, {Keys::KEY_7, SDLK_7},
        {Keys::KEY_8, SDLK_8}, {Keys::KEY_9, SDLK_9}};

    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_KEYDOWN: {
                for (auto it : code)
                    if (sdlEvent.key.keysym.sym == it.second) {
                        ANAL::Event ev;
                        ev.keyEvent->key = it.first;
                        this->_sdlEvents.push_back(ev);
                        break;
                    }
                break;
            }
            case SDL_QUIT: {
                ANAL::Event ev;
                ev.keyEvent->key = Keys::KEY_Q;
                this->_sdlEvents.push_back(ev);
                break;
            }
            default:
                break;
        }
    }
    return this->_sdlEvents;
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

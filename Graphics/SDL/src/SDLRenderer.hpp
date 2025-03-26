//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SDLRenderer.hpp
//

#include "ARenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace ANAL {
    class SDLRenderer : public ARenderer {
       public:
        SDLRenderer();
        ~SDLRenderer() override;

        void drawEntity(const ANAL::IEntity &entity) override;

        void drawText(const std::string &str, ANAL::Vector2<int> pos) override;

        void setWindowTitle(const std::string &windowTitle) override;

        void render() override;

        std::vector<ANAL::Event> &getEvents() override;

        void clear() override;
       private:
        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
    };

}  // namespace ANAL

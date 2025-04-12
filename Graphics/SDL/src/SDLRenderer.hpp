//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SDLRenderer.hpp
//

#include "ARenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

namespace ANAL {

/**
 * @class SDLRenderer
 * @brief Renderer implementation.
 *
 * This class provides concrete rendering functionalities using SDL2 and SDL_ttf. It handles
 * drawing entities, rendering text, managing events, and interacting with the SDL window and renderer.
 */
class SDLRenderer : public ARenderer {
   public:
    /**
     * @brief Constructs the SDLRenderer and initializes SDL2 and related resources.
     */
    SDLRenderer();

    /**
     * @brief Destructor that cleans up all SDL2 resources.
     */
    ~SDLRenderer() override;

    /**
     * @brief Draws an entity on the screen.
     * @param entity The entity to draw.
     */
    void drawEntity(const ANAL::IEntity &entity) override;

    /**
     * @brief Renders text at a specified position.
     * @param str The string to render.
     * @param pos The position where the text will be drawn.
     */
    void drawText(const std::string &str, ANAL::Vector2<int> pos) override;

    /**
     * @brief Sets the title of the SDL window.
     * @param windowTitle The new title for the window.
     */
    void setWindowTitle(const std::string &windowTitle) override;

    /**
     * @brief Displays the rendered content on screen.
     */
    void render() override;

    /**
     * @brief Retrieves a reference to the list of events captured since the last frame.
     * @return A reference to a vector of ANAL::Event.
     */
    std::vector<ANAL::Event> &getEvents() override;

    /**
     * @brief Clears the current rendering target.
     */
    void clear() override;

   private:
    SDL_Window *_window = nullptr;              ///< SDL window handle.
    SDL_Renderer *_renderer = nullptr;          ///< SDL renderer handle.
    TTF_Font *font = nullptr;                   ///< Font used for rendering text.
    std::vector<ANAL::Event> _sdlEvents;        ///< List of SDL events translated to ANAL::Event.
};

}  // namespace ANAL

//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// ARenderer.hpp
//

#pragma once

#include "IRenderer.hpp"
#include "IEntity.hpp"
#include "Vector2.hpp"
#include <vector>

namespace ANAL {

/**
 * @class ARenderer
 * @brief Abstract base class for rendering implementations.
 *
 * This class provides a common interface and shared attributes for all concrete renderers.
 * It inherits from IRenderer and defines pure virtual functions that must be implemented
 * by any backend renderer (e.g., SDL, SFML, Ncurses, etc.).
 */
class ARenderer : public ANAL::IRenderer {
   public:
    /**
     * @brief Virtual destructor.
     */
    ~ARenderer() override = default;

    /**
     * @brief Draws a given entity on the screen.
     * @param entity The entity to render.
     */
    void drawEntity(const ANAL::IEntity &entity) override = 0;

    /**
     * @brief Draws a text string at the specified position.
     * @param str The text to render.
     * @param pos The position (in pixels or units depending on implementation) to draw the text.
     */
    void drawText(const std::string &str, ANAL::Vector2<int> pos) override = 0;

    /**
     * @brief Sets the title of the rendering window.
     * @param windowTitle The new title to display on the window.
     */
    void setWindowTitle(const std::string &windowTitle) override = 0;

    /**
     * @brief Presents the current rendering buffer to the screen.
     */
    void render() override = 0;

    /**
     * @brief Returns the list of input or system events since the last frame.
     * @return A reference to a vector of ANAL::Event.
     */
    std::vector<ANAL::Event> &getEvents() override = 0;

    /**
     * @brief Clears the current rendering target or screen buffer.
     */
    void clear() override = 0;

   protected:
    float _windowWidth = 900;             ///< Default window width.
    float _windowHeight = 900;            ///< Default window height.
    std::string _windowTitle = "PlaceHolder"; ///< Default window title.
};

}  // namespace ANAL

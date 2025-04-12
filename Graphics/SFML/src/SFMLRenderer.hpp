//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SFMLRenderer.hpp
//

#include "ARenderer.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace ANAL {
    /**
     * @class SFMLRenderer
     * @brief SFML-based rendering class.
     *
     * The SFMLRenderer class inherits from ARenderer and provides an implementation of methods
     * to draw entities, render text, handle events, and manage the rendering window.
     */
    class SFMLRenderer : public ARenderer {
       public:
        /**
         * @brief Default constructor of SFMLRenderer.
         *
         * Initializes an instance of SFMLRenderer and sets up the necessary resources for
         * graphical rendering.
         */
        SFMLRenderer();

        /**
         * @brief Destructor of SFMLRenderer.
         *
         * Releases the resources allocated by the SFMLRenderer.
         */
        ~SFMLRenderer() override;

        /**
         * @brief Draws an entity in the rendering window.
         *
         * This method takes a reference to an entity and draws it within the window.
         *
         * @param entity A reference to the entity to be drawn.
         */
        void drawEntity(const ANAL::IEntity &entity) override;

        /**
         * @brief Renders text in the rendering window.
         *
         * Displays a string at a specified position.
         *
         * @param str The string to display.
         * @param pos The position (x and y coordinates) where the text will be displayed.
         */
        void drawText(const std::string &str, ANAL::Vector2<int> pos) override;

        /**
         * @brief Sets the title of the rendering window.
         *
         * Updates the title in the window's title bar.
         *
         * @param windowTitle The new title for the rendering window.
         */
        void setWindowTitle(const std::string &windowTitle) override;

        /**
         * @brief Renders the scene.
         *
         * Displays the content drawn in the window. This method should be called after all
         * scene elements have been drawn to update the display.
         */
        void render() override;

        /**
         * @brief Retrieves the list of events.
         *
         * Returns a reference to the vector containing the events captured by SFML.
         *
         * @return A reference to a std::vector containing events of type ANAL::Event.
         */
        std::vector<ANAL::Event> &getEvents() override;

        /**
         * @brief Clears the rendering window.
         *
         * Prepares the window for the next rendering cycle by clearing the previous display.
         */
        void clear() override;

       private:
        std::unique_ptr<sf::RenderWindow> _window = nullptr;
        std::unique_ptr<sf::Font> _font = nullptr;
        std::vector<ANAL::Event> _sfmlEvents;
    };

}  // namespace ANAL

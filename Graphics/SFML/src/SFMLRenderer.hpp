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
    class SFMLRenderer : public ARenderer {
       public:
        SFMLRenderer();
        ~SFMLRenderer() override;

        void drawEntity(const ANAL::IEntity &entity) override;

        void drawText(const std::string &str, ANAL::Vector2<int> pos) override;

        void setWindowTitle(const std::string &windowTitle) override;

        void render() override;

        std::vector<ANAL::Event> &getEvents() override;

        void clear() override;

       private:
        std::unique_ptr<sf::RenderWindow> _window = nullptr;
        std::unique_ptr<sf::Font> _font = nullptr;
        std::vector<ANAL::Event> _sfmlEvents;
    };

}  // namespace ANAL


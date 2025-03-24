//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// ARenderer.hpp
//

#pragma once

#include "IRenderer.hpp"
#include "ISprite.hpp"
#include "Vector2.hpp"

namespace Graphics {
    class ARenderer : public ANAL::IRenderer {
       public:
            void drawSprite(const ANAL::ISprite& sprite) override;

            void drawText(const std::string& str, ANAL::Vector2<int> pos) override;

            void setWindowTitle(const std::string& windowTitle) override;

            void render() override;

            std::vector<ANAL::Event>& getEvents() override;

            void clear() override;
       private:
       protected:
    };
}  // namespace Graphics

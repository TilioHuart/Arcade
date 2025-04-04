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
    class ARenderer : public ANAL::IRenderer {
       public:
        ~ARenderer() override = default;
        void drawEntity(const ANAL::IEntity &entity) override = 0;

        void drawText(const std::string &str, ANAL::Vector2<int> pos) override = 0;

        void setWindowTitle(const std::string &windowTitle) override = 0;

        void render() override = 0;

        std::vector<ANAL::Event> &getEvents() override = 0;

        void clear() override = 0;

       protected:
        float _windowWidth = 900;
        float _windowHeight = 900;
        std::string _windowTitle = "PlaceHolder";
    };
}  // namespace ANAL

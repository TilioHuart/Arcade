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
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

namespace ANAL {
    class ARenderer : public ANAL::IRenderer {
       public:
        void drawEntity(const ANAL::IEntity &entity) override;

        void drawText(const std::string &str, ANAL::Vector2<int> pos) override;

        void setWindowTitle(const std::string &windowTitle) override;

        void render() override;

        std::vector<ANAL::Event> &getEvents() override;

        void clear() override;

       protected:
        int _windowWidth = 900;
        int _windowHeight = 600;
        std::string _windowTitle = "PlaceHolder";
    };
}  // namespace ANAL

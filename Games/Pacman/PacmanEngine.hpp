//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// PacmanEngine.hpp
//

#pragma once

#include "AGame.hpp"
#include "IRenderer.hpp"

namespace game {
    class PacmanEngine : public game::AGame {
       public:
        PacmanEngine();
        void processEvents(const std::vector<ANAL::Event> &event) override;
        void compute() override;
        void render(ANAL::IRenderer& renderer) override;

       private:
    };
}  // namespace game

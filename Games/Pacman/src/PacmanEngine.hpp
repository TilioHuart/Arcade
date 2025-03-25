//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// PacmanEngine.hpp
//

#pragma once

#include "Games/AGame.hpp"
#include "IRenderer.hpp"

namespace ANAL {
    class PacmanEngine : public ANAL::AGame {
       public:
        PacmanEngine();
        void processEvents(std::vector<Event> &Event) override;
        void compute() override;
        void render(ANAL::IRenderer &renderer, ANAL::IArcade &arcade) override;

       private:
    };
}  // namespace ANAL

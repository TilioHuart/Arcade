//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// PacmanEngine.hpp
//

#pragma once

#include "AGame.hpp"
#include "IArcade.hpp"
#include "IRenderer.hpp"

namespace ANAL {
    class PacmanEngine : public ANAL::AGame {
       public:
        PacmanEngine();
        void processEvents(std::vector<Event> &Event) override;
        void compute(IArcade &arcade) override;
        void render(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
    };
}  // namespace ANAL

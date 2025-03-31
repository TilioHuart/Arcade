//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"

namespace Arcade {
    class MenuEngine : public ANAL::AGame {
       public:
        MenuEngine();
        ~MenuEngine() override;

        void processEvents(std::vector<ANAL::Event> &Event) override;
        void compute() override;
        void render(ANAL::IRenderer &renderer, ANAL::IArcade &arcade) override;

    };
}  // namespace Arcade

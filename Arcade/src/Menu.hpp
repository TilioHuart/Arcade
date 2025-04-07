//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"
#include <string>
#include "IRenderer.hpp"
#include <string>
#include <utility>
#include <vector>

namespace Arcade {
    class MenuEngine : public ANAL::AGame {
       public:
        MenuEngine();
        ~MenuEngine() override {};

        void processEvents(std::vector<ANAL::Event> &Event) override;

        void compute() override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        std::vector<std::pair<std::string, bool>> _games;
        std::vector<std::pair<std::string, bool>> _renderer;

        void retrieveModules();
    };
}  // namespace Arcade

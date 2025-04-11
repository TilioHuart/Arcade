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
#include "IArcade.hpp"
#include "IRenderer.hpp"
#include <utility>
#include <vector>

namespace Arcade {
    class MenuEngine : public ANAL::AGame {
       public:
        MenuEngine();
        ~MenuEngine() override {};

        void processEvents(std::vector<ANAL::Event> &Event) override;

        void compute(ANAL::IArcade &arcade) override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;
        std::string getGame();
        std::string getRenderer();

       private:
        std::vector<std::string> _games;
        std::vector<std::string> _renderers;
        size_t _actualGame;
        size_t _actualRenderer;
        bool _launchGame;
    };
}  // namespace Arcade

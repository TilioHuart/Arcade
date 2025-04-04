//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Snake
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"

namespace anal {
    class SnakeEngine : public ANAL::AGame {
       public:
        SnakeEngine();
        ~SnakeEngine() override;
        void processEvents(std::vector<ANAL::Event> &Event) override;
        void compute() override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        void createMap();
    };

}  // namespace anal

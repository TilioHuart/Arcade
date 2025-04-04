//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"
#include <iostream>

namespace Arcade {
    class MenuEngine : public ANAL::AGame {
       public:
        MenuEngine() = default;
        ~MenuEngine() override {};

        void processEvents(std::vector<ANAL::Event> &Event) override
        {
            for (auto &it : Event) {
                if (it.type == ANAL::EventType::MOUSE) {
                    std::cout
                        << "Astalavista baby\nx:" << it.mouseEvent->coords.x
                        << "\ny:" << it.mouseEvent->coords.y << std::endl;
                }
            }
        };

        void compute() override {};
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;
    };
}  // namespace Arcade

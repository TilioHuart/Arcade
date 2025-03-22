//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// AGame.hpp
//

#pragma once

#include "Events.hpp"
#include "IGame.hpp"

namespace game {
    class AGame : public ANAL::IGame {
       public:
        void processEvents(const std::vector<ANAL::Event> &) override = 0;
        void compute() override = 0;
        void render() override = 0;
       protected:
    };

}  // namespace game

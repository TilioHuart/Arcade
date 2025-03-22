//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// PacmanEngine.hpp
//

#pragma once

#include "src/Games/AGame.hpp"

namespace game {
    class PacmanEngine : public game::AGame {
       public:
        void processEvents(const std::vector<ANAL::Event> &) override;
        void compute() override;
        void render() override;

       private:
    };
}  // namespace game

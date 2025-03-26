//
// EPITECH PROJECT, 2025
// Minesweeper Engine
// File description:
// Minesweeper Engine
//

#pragma once

#include "AGame.hpp"

namespace ANAL {
    class MinesweeperEngine : public AGame {
       public:
        MinesweeperEngine();
        ~MinesweeperEngine() override;
        void processEvents(std::vector<Event>& Event) override;
        void compute() override;
        void render(ANAL::IRenderer &renderer, ANAL::IArcade& arcade) override;
       private:
    };
}  // namespace ANAL

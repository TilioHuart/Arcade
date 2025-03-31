//
// EPITECH PROJECT, 2025
// Minesweeper Engine
// File description:
// Minesweeper Engine
//

#pragma once

#include "AGame.hpp"
#include <cstdint>

namespace ANAL {
    enum class Difficulty : std::uint8_t { EASY, NORMAL, HARD };

    enum class Case : std::uint8_t {
        EMPTY,
        NEAR1,
        NEAR2,
        NEAR3,
        NEAR4,
        NEAR5,
        NEAR6,
        NEAR7,
        NEAR8,
        MINE
    };

    class MinesweeperEngine : public AGame {
       public:
        MinesweeperEngine();
        ~MinesweeperEngine() override;
        void processEvents(std::vector<Event> &Event) override;
        void compute() override;
        void render(ANAL::IRenderer &renderer, ANAL::IArcade &arcade) override;

       private:
        Difficulty _difficulty = Difficulty::EASY;
        size_t _nbMine = 10;
        size_t _nbMineLeft = 10;
        size_t _gridSize = 9;
        std::vector<std::vector<ANAL::Case>> _map;
        void _createMap();
        void _createEasyMap();
        void _createNormalMap();
        void _createHardMap();
        void _placeMines();
        void _setNeighbors();
    };
}  // namespace ANAL

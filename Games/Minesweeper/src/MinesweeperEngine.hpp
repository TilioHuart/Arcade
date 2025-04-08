//
// EPITECH PROJECT, 2025
// Minesweeper Engine
// File description:
// Minesweeper Engine
//

#pragma once

#include "AGame.hpp"
#include "IArcade.hpp"
#include "IRenderer.hpp"
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

    enum class Visibility : std::uint8_t { HIDDEN, VISIBLE, FLAG };

    Case &operator++(Case &origine);

    class MinesweeperEngine : public AGame {
       public:
        MinesweeperEngine();
        ~MinesweeperEngine() override;
        void processEvents(std::vector<Event> &Event) override;
        void compute() override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        Difficulty _difficulty = Difficulty::NORMAL;
        size_t _score = 0;
        uint16_t _nbMine = 10;
        uint16_t _nbMineLeft = 10;
        uint16_t _nbFlags = 0;
        uint16_t _gridSize = 10;
        bool _hasLose = false;
        bool _mineDisplayed = false;
        std::vector<std::vector<ANAL::Case>> _map;
        std::vector<std::vector<ANAL::Visibility>> _hidden;

        void _propagateEmpty(int xPos, int yPos);
        void _restartGame();

        void _createMap();
        void _createEasyMap();
        void _createNormalMap();
        void _createHardMap();

        void _placeMines();
        void _setNeighbors();
        void _createHidden();

        void _renderBackground(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const;
        void _renderCases(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const;
        void _renderAth(ANAL::IRenderer &renderer) const;
        void _displayHidden(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;
        void _displayVisible(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;
        void _displayFlag(ANAL::IRenderer &renderer,
            const ANAL::IArcade &arcade, size_t i, size_t j) const;
        void _displayMines(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
        void _displayLose(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
    };
}  // namespace ANAL

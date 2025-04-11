//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Snake
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"
#include "IArcade.hpp"
#include "Vector2.hpp"
#include <cstdint>
#include <vector>

namespace ANAL {
    enum class STATE : std::uint8_t { EMPTY, FRUIT, SNAKE, HEAD };

    enum class DIRECTION : std::uint8_t { UP, DOWN, LEFT, RIGHT };

    enum class VICTORY : std::uint8_t { YES, NO, UNDEFINED };

    class SnakeEngine : public ANAL::AGame {
       public:
        SnakeEngine();
        ~SnakeEngine() override;
        void processEvents(std::vector<ANAL::Event> &Event) override;
        void compute(ANAL::IArcade &arcade) override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        std::vector<std::vector<STATE>> map;
        std::vector<ANAL::Vector2<int>> snake;
        int fruitX;
        int fruitY;
        int mapSize = 16;
        uint8_t fruitPos = 0;
        bool fruitEaten = true;
        int previousX;
        int previousY;
        DIRECTION snakeDirection = DIRECTION::RIGHT;
        uint8_t snakeCompute = 0;
        VICTORY gameState = VICTORY::UNDEFINED;
        int score = 0;

        void createMap();
        void setSnake();
        void setFruit();
        void renderMap(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
        void renderFruit(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
        void renderSnake(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
        void renderScore(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade);
        void computeSnake();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        void resetGame();
        void checkWinCondition();
    };

}  // namespace ANAL

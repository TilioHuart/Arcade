//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Snake
//

#pragma once

#include "AGame.hpp"
#include "Events.hpp"
#include <cstdint>
#include <vector>

namespace anal {
    enum class STATE : std::uint8_t { EMPTY, FRUIT, SNAKE, HEAD };

    class SnakeEngine : public ANAL::AGame {
       public:
        SnakeEngine();
        ~SnakeEngine() override;
        void processEvents(std::vector<ANAL::Event> &Event) override;
        void compute() override;
        void render(
            ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) override;

       private:
        std::vector<std::vector<STATE>> map;
        uint8_t mapSize = 15;
        uint8_t fruitPos = 0;

        void createMap();
        void setSnake();
        void setFruit();
    };

}  // namespace anal

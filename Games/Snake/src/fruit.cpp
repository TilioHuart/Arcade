//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Fruit.cpp
//

#include "SnakeEngine.hpp"
#include <cstdint>

void anal::SnakeEngine::setFruit()
{
    uint8_t counter = 0;
    uint8_t newCounter = 0;

    for (const auto &it : this->map)
        for (auto elt : it)
            if (elt == STATE::EMPTY)
                counter += 1;

    srand (time(nullptr));
    uint8_t newFruit = rand() % counter;

    for (const auto &it : this->map)
        for (auto elt : it) {
            if (newCounter == newFruit)
                elt = STATE::FRUIT;
            if (elt == STATE::EMPTY)
                newCounter += 1;
    }
}

//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Fruit.cpp
//

#include "SnakeEngine.hpp"
#include <iostream>

void ANAL::SnakeEngine::setFruit()
{
    if (!fruitEaten)
        return;
    int counter = 0;
    int newCounter = 0;

    for (const auto &it : this->map)
        for (auto elt : it) {
            if (elt == STATE::EMPTY)
                counter += 1;
        }

    srand(time(nullptr));
    int newFruit = rand() % counter;

    int i = 0;
    int y = 0;
    for (auto &it : this->map) {
        for (auto &elt : it) {
            if (newCounter == newFruit) {
                std::cout << "New fruit at " << newCounter << "\n";
                elt = STATE::FRUIT;
                this->fruitX = y;
                this->fruitY = i;
                this->fruitEaten = false;
                return;
            }
            if (elt == STATE::EMPTY)
                newCounter += 1;
            i += 1;
        }
        y += 1;
        i = 0;
    }
}

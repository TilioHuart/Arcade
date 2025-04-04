//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// map.cpp
//

#include "SnakeEngine.hpp"
#include <vector>

void anal::SnakeEngine::createMap()
{
    this->map.clear();
    this->map.resize(this->mapSize);

    for (auto it : this->map)
        it.resize(this->mapSize, STATE::EMPTY);
}

void anal::SnakeEngine::setSnake()
{
    this->map[(this->mapSize / 2) + 1][(this->mapSize / 2) + 1] = STATE::HEAD;
}

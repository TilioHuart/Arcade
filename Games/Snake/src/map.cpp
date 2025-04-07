//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// map.cpp
//

#include "SnakeEngine.hpp"
#include <vector>

void ANAL::SnakeEngine::createMap()
{
    this->map.clear();
    this->map.resize(this->mapSize);

    for (auto &it : this->map)
        it.resize(this->mapSize, STATE::EMPTY);
}


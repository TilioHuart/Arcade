//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// base.cpp
//

#include "Events.hpp"
#include "SnakeEngine.hpp"
#include <iostream>
#include <ostream>
#include <vector>

anal::SnakeEngine::SnakeEngine()
{
    std::cout << "Init of Snake" << std::endl;
    this->createMap();
    this->setSnake();
}

anal::SnakeEngine::~SnakeEngine() {
    std::cout << "Destroy of Snake" << std::endl;
}

void anal::SnakeEngine::compute()
{
    this->setFruit();
}

void anal::SnakeEngine::processEvents(std::vector<ANAL::Event> &event) {}

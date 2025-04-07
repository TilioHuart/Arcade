//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// base.cpp
//

#include "Events.hpp"
#include "IModule.hpp"
#include "SnakeEngine.hpp"
#include <iostream>
#include <ostream>
#include <vector>

ANAL::SnakeEngine::SnakeEngine()
{
    std::cout << "Init of Snake" << std::endl;
    this->createMap();
    this->setSnake();
    this->setFruit();
    std::cout << "Init of Snake" << std::endl;
}

ANAL::SnakeEngine::~SnakeEngine()
{
    std::cout << "Destroy of Snake" << std::endl;
}

void ANAL::SnakeEngine::compute()
{
    if (this->gameState != VICTORY::UNDEFINED)
        return;
    this->setFruit();
    this->computeSnake();
    if (this->snake[0].x == this->fruitX && this->snake[0].y == this->fruitY && !this->fruitEaten) {
        this->fruitEaten = true;
        this->snake.push_back({this->previousX, this->previousY});
    }
}

void ANAL::SnakeEngine::processEvents(std::vector<ANAL::Event> &event)
{
    if (this->gameState != VICTORY::UNDEFINED)
        return;
    for (const auto &elem : event) {
        if (elem.keyEvent->key == ANAL::Keys::KEY_A)
            this->snakeDirection = DIRECTION::LEFT;
        if (elem.keyEvent->key == ANAL::Keys::KEY_S)
            this->snakeDirection = DIRECTION::DOWN;
        if (elem.keyEvent->key == ANAL::Keys::KEY_W)
            this->snakeDirection = DIRECTION::UP;
        if (elem.keyEvent->key == ANAL::Keys::KEY_D)
            this->snakeDirection = DIRECTION::RIGHT;
    }
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::GAME;
}

std::unique_ptr<ANAL::IGame> uwu_entrypoint_game(void)
{
    return std::make_unique<ANAL::SnakeEngine>();
}
}

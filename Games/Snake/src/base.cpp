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
}

ANAL::SnakeEngine::~SnakeEngine()
{
    std::cout << "Destroy of Snake" << std::endl;
}

void ANAL::SnakeEngine::compute()
{
    if (this->gameState != VICTORY::UNDEFINED)
        return;
    this->checkWinCondition();
    this->computeSnake();
    this->setFruit();
    if (this->snake[0].x == this->fruitX && this->snake[0].y == this->fruitY &&
        !this->fruitEaten) {
        this->fruitEaten = true;
        this->map[this->fruitX][this->fruitY] = STATE::FRUIT;
        score += 1;
        this->snake.push_back({this->previousX, this->previousY});
        this->map[this->previousX][this->previousY] = STATE::SNAKE;
    }
}

void ANAL::SnakeEngine::processEvents(std::vector<ANAL::Event> &event)
{
    if (this->gameState != VICTORY::UNDEFINED)
        for (const auto &elem : event) {
            if (elem.keyEvent->key == ANAL::Keys::KEY_R)
                this->resetGame();
            return;
        }
    for (const auto &elem : event) {
        if (elem.keyEvent->key == ANAL::Keys::ARROW_LEFT)
            this->snakeDirection = DIRECTION::LEFT;
        if (elem.keyEvent->key == ANAL::Keys::ARROW_DOWN)
            this->snakeDirection = DIRECTION::DOWN;
        if (elem.keyEvent->key == ANAL::Keys::ARROW_UP)
            this->snakeDirection = DIRECTION::UP;
        if (elem.keyEvent->key == ANAL::Keys::ARROW_RIGHT)
            this->snakeDirection = DIRECTION::RIGHT;
        if (elem.keyEvent->key == ANAL::Keys::KEY_R)
            this->resetGame();
    }
}

void ANAL::SnakeEngine::resetGame()
{
    this->snakeDirection = DIRECTION::RIGHT;
    this->gameState = VICTORY::UNDEFINED;
    this->createMap();
    this->setSnake();
    this->fruitEaten = true;
    this->score = 0;
    this->setFruit();
}

void ANAL::SnakeEngine::checkWinCondition()
{
    if (this->gameState != VICTORY::UNDEFINED)
        return;
    if (this->snake.size() == (this->mapSize * this->mapSize - 1)) {
        this->gameState = VICTORY::YES;
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

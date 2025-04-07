//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Snake.cpp
//

#include "SnakeEngine.hpp"
#include <iostream>

void ANAL::SnakeEngine::setSnake()
{
    this->snake.push_back({this->mapSize / 2, this->mapSize / 2});
    this->previousX = this->mapSize / 2;
    this->previousY = this->mapSize / 2;
    this->snake.push_back({this->previousX -= 1, this->previousY});
    this->snake.push_back({this->previousX -= 1, this->previousY});
    this->snake.push_back({this->previousX -= 1, this->previousY});
}

void ANAL::SnakeEngine::computeSnake()
{
    if (this->snakeCompute < 10) {
        this->snakeCompute += 1;
        return;
    }
    if (snakeDirection == DIRECTION::RIGHT)
        this->moveRight();
    if (snakeDirection == DIRECTION::LEFT)
        this->moveLeft();
    if (snakeDirection == DIRECTION::UP)
        this->moveUp();
    if (snakeDirection == DIRECTION::DOWN)
        this->moveDown();
    this->snakeCompute = 0;
}

void ANAL::SnakeEngine::moveRight()
{
    bool head = true;
    if (this->snake[0].x + 1 >= this->mapSize) {
        this->gameState = VICTORY::NO;
        return;
    }
    for (auto &it : this->snake) {
        if (head) {
            this->previousX = it.x;
            this->previousY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x += 1;
            head = false;
        } else {
            int tmpX = it.x;
            int tmpY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x = previousX;
            it.y = previousY;
            this->map[it.x][it.y] = STATE::SNAKE;
            previousX = tmpX;
            previousY = tmpY;
        }
    }
}

void ANAL::SnakeEngine::moveLeft()
{
    bool head = true;
    if (this->snake[0].x - 1 < 0) {
        this->gameState = VICTORY::NO;
        return;
    }
    for (auto &it : this->snake) {
        if (head) {
            this->previousX = it.x;
            this->previousY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x -= 1;
            this->map[it.x][it.y] = STATE::SNAKE;
            head = false;
        } else {
            int tmpX = it.x;
            int tmpY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x = previousX;
            it.y = previousY;
            this->map[it.x][it.y] = STATE::SNAKE;
            previousX = tmpX;
            previousY = tmpY;
        }
    }
}

void ANAL::SnakeEngine::moveUp()
{
    bool head = true;
    if (this->snake[0].y - 1 < 0) {
        this->gameState = VICTORY::NO;
        return;
    }
    for (auto &it : this->snake) {
        if (head) {
            this->previousX = it.x;
            this->previousY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.y -= 1;
            this->map[it.x][it.y] = STATE::SNAKE;
            head = false;
        } else {
            int tmpX = it.x;
            int tmpY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x = previousX;
            it.y = previousY;
            this->map[it.x][it.y] = STATE::SNAKE;
            previousX = tmpX;
            previousY = tmpY;
        }
    }
}

void ANAL::SnakeEngine::moveDown()
{
    bool head = true;
    if (this->snake[0].y + 1 >= this->mapSize) {
        this->gameState = VICTORY::NO;
        return;
    }
    for (auto &it : this->snake) {
        if (head) {
            this->previousX = it.x;
            this->previousY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.y += 1;
            this->map[it.x][it.y] = STATE::SNAKE;
            head = false;
        } else {
            int tmpX = it.x;
            int tmpY = it.y;
            this->map[it.x][it.y] = STATE::EMPTY;
            it.x = previousX;
            it.y = previousY;
            this->map[it.x][it.y] = STATE::SNAKE;
            previousX = tmpX;
            previousY = tmpY;
        }
    }
}

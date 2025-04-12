//
// EPITECH PROJECT, 2025
// Gameplay
// File description:
// Gameplay
//

#include "Events.hpp"
#include "MinesweeperEngine.hpp"
#include <iostream>

void ANAL::MinesweeperEngine::processEvents(std::vector<ANAL::Event> &Event)
{
    for (auto &it : Event) {
        if (this->_hasLose || this->_hasWin) {
            if (it.keyEvent->key == ANAL::Keys::KEY_R) {
                this->_restartGame();
            }
            return;
        }
        if (it.type == ANAL::EventType::MOUSE) {
            auto xPos = it.mouseEvent->coords.x;
            auto yPos = it.mouseEvent->coords.y;
            auto mouseKey = it.mouseEvent->key;

            if (xPos >= this->_gridSize || yPos >= this->_gridSize) {
                continue;
            }
            this->_clickLeft(it);
            this->_clickRight(it);
        }
        if (it.type == ANAL::EventType::KEYBOARD &&
            it.keyEvent->state == State::RELEASED) {
            if (it.keyEvent->key == ANAL::Keys::ARROW_RIGHT) {
                this->_changeDifficultyUp();
                return;
            }
            if (it.keyEvent->key == ANAL::Keys::ARROW_LEFT) {
                this->_changeDifficultyDown();
                return;
            }
        }
    }
}

void ANAL::MinesweeperEngine::_changeDifficultyUp()
{
    switch (this->_difficulty) {
        case ANAL::Difficulty::EASY:
            this->_difficulty = ANAL::Difficulty::NORMAL;
            break;
        case ANAL::Difficulty::NORMAL:
            this->_difficulty = ANAL::Difficulty::HARD;
            break;
        default:
            return;
    }
    this->_restartGame();
}

void ANAL::MinesweeperEngine::_changeDifficultyDown()
{
    switch (this->_difficulty) {
        case ANAL::Difficulty::NORMAL:
            this->_difficulty = ANAL::Difficulty::EASY;
            break;
        case ANAL::Difficulty::HARD:
            this->_difficulty = ANAL::Difficulty::NORMAL;
            break;
        default:
            return;
    }
    this->_restartGame();
}

void ANAL::MinesweeperEngine::_clickLeft(const Event &event)
{
    auto xPos = event.mouseEvent->coords.x;
    auto yPos = event.mouseEvent->coords.y;
    auto mouseKey = event.mouseEvent->key;

    if (mouseKey == MouseKeys::LEFT_CLICK) {
        if (this->_firstClick) {
            this->_clickLeftFirst(event);
        }
        if (this->_map[xPos][yPos] != ANAL::Case::EMPTY &&
            this->_map[xPos][yPos] != ANAL::Case::MINE) {
            this->_score += 1;
        }
        if (this->_map[xPos][yPos] == ANAL::Case::EMPTY) {
            this->_propagateEmpty(xPos, yPos);
        }
        if (this->_hidden[xPos][yPos] == ANAL::Visibility::FLAG) {
            this->_nbFlags -= 1;
        }
        this->_hidden[xPos][yPos] = ANAL::Visibility::VISIBLE;
    }
}

void ANAL::MinesweeperEngine::_clickLeftFirst(const Event &event)
{
    auto xPos = event.mouseEvent->coords.x;
    auto yPos = event.mouseEvent->coords.y;
    auto mouseKey = event.mouseEvent->key;

    size_t index = 0;

    while (this->_firstClick && this->_map[xPos][yPos] != Case::EMPTY) {
        this->_restartGame();
        index += 1;
    }
    this->_endTime = std::chrono::steady_clock::now() +
                     std::chrono::seconds(this->_nbMine * 10);
    this->_firstClick = false;
}

void ANAL::MinesweeperEngine::_clickRight(const Event &event)
{
    auto xPos = event.mouseEvent->coords.x;
    auto yPos = event.mouseEvent->coords.y;
    auto mouseKey = event.mouseEvent->key;

    if (mouseKey == MouseKeys::RIGHT_CLICK) {
        if (this->_hidden[xPos][yPos] == ANAL::Visibility::HIDDEN) {
            this->_hidden[xPos][yPos] = ANAL::Visibility::FLAG;
            this->_nbFlags += 1;
            return;
        }
        if (this->_hidden[xPos][yPos] == ANAL::Visibility::FLAG) {
            this->_hidden[xPos][yPos] = ANAL::Visibility::HIDDEN;
            this->_nbFlags -= 1;
            return;
        }
    }
}

void ANAL::MinesweeperEngine::_propagateEmpty(int xPos, int yPos)
{
    if (xPos < 0 || xPos >= this->_gridSize || yPos < 0 ||
        yPos >= this->_gridSize ||
        this->_hidden[xPos][yPos] == ANAL::Visibility::VISIBLE)
        return;
    this->_hidden[xPos][yPos] = ANAL::Visibility::VISIBLE;
    if (this->_map[xPos][yPos] == ANAL::Case::MINE)
        return;
    this->_score += 1;
    if (this->_map[xPos][yPos] == ANAL::Case::EMPTY) {
        if (xPos > 0) {
            this->_propagateEmpty(xPos - 1, yPos);
            if (yPos > 0) {
                this->_propagateEmpty(xPos - 1, yPos - 1);
            }
            if (yPos < this->_gridSize) {
                this->_propagateEmpty(xPos - 1, yPos + 1);
            }
        }
        if (xPos < this->_gridSize) {
            this->_propagateEmpty(xPos + 1, yPos);
            if (yPos > 0) {
                this->_propagateEmpty(xPos + 1, yPos - 1);
            }
            if (yPos < this->_gridSize) {
                this->_propagateEmpty(xPos + 1, yPos + 1);
            }
        }
        if (yPos > 0) {
            this->_propagateEmpty(xPos, yPos - 1);
        }
        if (yPos < this->_gridSize) {
            this->_propagateEmpty(xPos, yPos + 1);
        }
    }
}

void ANAL::MinesweeperEngine::_checkWin()
{
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_map[i][j] != Case::MINE &&
                this->_hidden[i][j] != ANAL::Visibility::VISIBLE)
                return;
        }
    }
    if (!this->_added) {
        std::chrono::duration<double> timeLeft =
            this->_endTime - std::chrono::steady_clock::now();
        this->_score += static_cast<size_t>(timeLeft.count());
        this->_added = true;
    }

    this->_hasWin = true;
}

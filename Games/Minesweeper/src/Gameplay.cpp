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
                this->_hasLose = false;
                this->_hasWin = false;
                this->_firstClick = true;
                this->_mineDisplayed = false;
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
            if (mouseKey == MouseKeys::LEFT_CLICK) {
                while (this->_firstClick && this->_map[xPos][yPos] != Case::EMPTY) {
                    this->_restartGame();
                }
                this->_firstClick = false;
                if (this->_map[xPos][yPos] != ANAL::Case::EMPTY &&
                    this->_map[xPos][yPos] != ANAL::Case::MINE) {
                    this->_score += 1;
                }
                if (this->_map[xPos][yPos] == ANAL::Case::EMPTY) {
                    this->_propagateEmpty(xPos, yPos);
                }
                this->_hidden[xPos][yPos] = ANAL::Visibility::VISIBLE;
            }
            if (mouseKey == MouseKeys::RIGHT_CLICK) {
                if (this->_hidden[xPos][yPos] == ANAL::Visibility::HIDDEN) {
                    this->_hidden[xPos][yPos] = ANAL::Visibility::FLAG;
                    this->_nbFlags += 1;
                    continue;
                }
                if (this->_hidden[xPos][yPos] == ANAL::Visibility::FLAG) {
                    this->_hidden[xPos][yPos] = ANAL::Visibility::HIDDEN;
                    this->_nbFlags -= 1;
                    continue;
                }
            }
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
            if (this->_map[i][j] != Case::MINE && this->_hidden[i][j] != ANAL::Visibility::VISIBLE)
                return;
        }
    }
    this->_hasWin = true;
}

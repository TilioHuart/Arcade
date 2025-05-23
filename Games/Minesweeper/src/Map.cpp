//
// EPITECH PROJECT, 2025
// Map
// File description:
// Map
//

#include "MinesweeperEngine.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void ANAL::MinesweeperEngine::_createMap()
{
    switch (this->_difficulty) {
        case ANAL::Difficulty::NORMAL:
            this->_createNormalMap();
            break;
        case ANAL::Difficulty::HARD:
            this->_createHardMap();
            break;
        default:
            this->_createEasyMap();
            break;
    }
}

void ANAL::MinesweeperEngine::_createEasyMap()
{
    this->_nbMine = 7;
    this->_nbMineLeft = 7;
    this->_gridSize = 10;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }
}

void ANAL::MinesweeperEngine::_createNormalMap()
{
    this->_nbMine = 30;
    this->_nbMineLeft = 30;
    this->_gridSize = 15;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }
}

void ANAL::MinesweeperEngine::_createHardMap()
{
    this->_nbMine = 60;
    this->_nbMineLeft = 60;
    this->_gridSize = 22;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }
}

void ANAL::MinesweeperEngine::_placeMines()
{
    size_t placedMines = 0;

    while (placedMines < this->_nbMine) {
        int column = std::rand() % this->_gridSize;
        int row = std::rand() % this->_gridSize;

        if (this->_map[column][row] == ANAL::Case::EMPTY) {
            this->_map[column][row] = ANAL::Case::MINE;
            placedMines += 1;
        }
    }
}

void ANAL::MinesweeperEngine::_setNeighbors()
{
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_map[i][j] == Case::MINE) {
                if (i > 0) {
                    if (j > 0) {
                        ++this->_map[i - 1][j - 1];
                    }
                    if (j < this->_gridSize - 1)
                        ++this->_map[i - 1][j + 1];
                    ++this->_map[i - 1][j];
                }
                if (i < this->_gridSize - 1) {
                    if (j > 0)
                        ++this->_map[i + 1][j - 1];
                    if (j < this->_gridSize - 1) {
                        ++this->_map[i + 1][j + 1];
                    }
                    ++this->_map[i + 1][j];
                }
                if (j > 0) {
                    ++this->_map[i][j - 1];
                }
                if (j < this->_gridSize - 1) {
                    ++this->_map[i][j + 1];
                }
            }
        }
    }
}

void ANAL::MinesweeperEngine::_createHidden()
{
    this->_hidden.clear();
    this->_hidden.resize(this->_gridSize);

    for (auto &line : this->_hidden) {
        line.resize(this->_gridSize, ANAL::Visibility::HIDDEN);
    }
}

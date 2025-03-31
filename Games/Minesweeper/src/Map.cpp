//
// EPITECH PROJECT, 2025
// Map
// File description:
// Map
//

#include "MinesweeperEngine.hpp"
#include <cstdlib>
#include <ctime>

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
    this->_nbMine = 10;
    this->_nbMineLeft = 10;
    this->_gridSize = 9;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }

    this->_placeMines();
    this->_setNeighbors();
}

void ANAL::MinesweeperEngine::_createNormalMap()
{
    this->_nbMine = 40;
    this->_nbMineLeft = 40;
    this->_gridSize = 16;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }

    this->_placeMines();
    this->_setNeighbors();
}

void ANAL::MinesweeperEngine::_createHardMap()
{
    this->_nbMine = 99;
    this->_nbMineLeft = 99;
    this->_gridSize = 22;

    this->_map.clear();
    this->_map.resize(this->_gridSize);

    for (auto &line : this->_map) {
        line.resize(this->_gridSize, ANAL::Case::EMPTY);
    }

    this->_placeMines();
    this->_setNeighbors();
}

void ANAL::MinesweeperEngine::_placeMines()
{
    size_t placedMines = 0;
    std::srand(std::time(nullptr));

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
                if (i < this->_gridSize - 1) {
                    ++this->_map[i][j + 1];
                }
            }
        }
    }
}

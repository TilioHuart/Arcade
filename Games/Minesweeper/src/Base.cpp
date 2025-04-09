//
// EPITECH PROJECT, 2025
// Base functions
// File description:
// Base functions
//

#include "Events.hpp"
#include "IGame.hpp"
#include "IModule.hpp"
#include "MinesweeperEngine.hpp"
#include <chrono>
#include <iostream>
#include <memory.h>

ANAL::MinesweeperEngine::MinesweeperEngine()
{
    this->_restartGame();
}

ANAL::MinesweeperEngine::~MinesweeperEngine() {}

void ANAL::MinesweeperEngine::compute()
{
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_hidden[i][j] == Visibility::VISIBLE &&
                this->_map[i][j] == Case::MINE)
                this->_hasLose = true;
        }
    }
    this->_checkWin();
}

void ANAL::MinesweeperEngine::_restartGame()
{
    this->_endTime =
        std::chrono::steady_clock::now() + std::chrono::seconds(this->_nbMine * 10);
    this->_added = false;
    this->_hasLose = false;
    this->_hasWin = false;
    this->_firstClick = true;
    this->_mineDisplayed = false;
    this->_score = 0;
    this->_nbFlags = 0;
    this->_createMap();
    this->_placeMines();
    this->_setNeighbors();
    this->_createHidden();
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::GAME;
}

std::unique_ptr<ANAL::IGame> uwu_entrypoint_game(void)
{
    return std::make_unique<ANAL::MinesweeperEngine>();
}
}

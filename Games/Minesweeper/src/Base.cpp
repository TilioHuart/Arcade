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
#include <iostream>
#include <memory.h>

ANAL::MinesweeperEngine::MinesweeperEngine()
{
    this->_createMap();
    this->_placeMines();
    this->_setNeighbors();
    this->_createHidden();
}

ANAL::MinesweeperEngine::~MinesweeperEngine() {}

void ANAL::MinesweeperEngine::processEvents(std::vector<ANAL::Event> &Event)
{
    for (auto &it : Event) {
        if (this->_hasLose) {
                if (it.keyEvent->key == ANAL::Keys::KEY_R) {
                    this->_hasLose = false;
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

void ANAL::MinesweeperEngine::compute()
{
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_hidden[i][j] == Visibility::VISIBLE &&
                this->_map[i][j] == Case::MINE)
                this->_hasLose = true;
        }
    }
}

void ANAL::MinesweeperEngine::_restartGame()
{
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

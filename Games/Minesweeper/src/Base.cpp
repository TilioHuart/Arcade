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
    std::cout << "Init of minesweeper" << std::endl;
    this->_createMap();
    this->_placeMines();
    this->_setNeighbors();
    this->_createHidden();
}

ANAL::MinesweeperEngine::~MinesweeperEngine()
{
    std::cout << "Destroy of minesweeper" << std::endl;
}

void ANAL::MinesweeperEngine::processEvents(std::vector<ANAL::Event> &Event)
{
    for (auto &it : Event) {
        if (it.type == ANAL::EventType::MOUSE) {
            auto xPos = it.mouseEvent->coords.x;
            auto yPos = it.mouseEvent->coords.y;
            if (xPos >= this->_gridSize || yPos >= this->_gridSize) {
                continue;
            }
            if (this->_hidden[xPos][yPos] == ANAL::Visibility::HIDDEN) {
                this->_hidden[xPos][yPos] = ANAL::Visibility::VISIBLE;
            }
        }
    }
}

void ANAL::MinesweeperEngine::compute() {}

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

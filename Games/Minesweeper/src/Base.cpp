//
// EPITECH PROJECT, 2025
// Base functions
// File description:
// Base functions
//

#include "IEntity.hpp"
#include "MinesweeperEngine.hpp"
#include <iostream>
#include <memory.h>

ANAL::MinesweeperEngine::MinesweeperEngine()
{
    std::cout << "Init of minesweeper" << std::endl;
    this->_createMap();
}

ANAL::MinesweeperEngine::~MinesweeperEngine()
{
    std::cout << "Destroy of minesweeper" << std::endl;
}

void ANAL::MinesweeperEngine::render(
    ANAL::IRenderer &renderer, ANAL::IArcade &arcade)
{
    auto entity = arcade.newEntity();
    renderer.drawEntity(*entity);
    renderer.render();
}

void processEvents(std::vector<ANAL::Event> &Event) {}

void compute() {}

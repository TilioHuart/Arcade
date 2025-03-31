//
// EPITECH PROJECT, 2025
// Base functions
// File description:
// Base functions
//

#include "Events.hpp"
#include "IAsset.hpp"
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


void processEvents(std::vector<ANAL::Event> &Event) {}

void compute() {}

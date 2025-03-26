//
// EPITECH PROJECT, 2025
// Base functions
// File description:
// Base functions
//

#include "MinesweeperEngine.hpp"
#include <iostream>

ANAL::MinesweeperEngine::MinesweeperEngine()
{
    std::cout << "Init of minesweeper" << std::endl;
}

ANAL::MinesweeperEngine::~MinesweeperEngine()
{
    std::cout << "Destroy of minesweeper" << std::endl;
}

void ANAL::MinesweeperEngine::render(
    ANAL::IRenderer &renderer, ANAL::IArcade &arcade)
{
    renderer.clear();
    renderer.render();
}

void processEvents(std::vector<ANAL::Event> &Event) {}

void compute() {}

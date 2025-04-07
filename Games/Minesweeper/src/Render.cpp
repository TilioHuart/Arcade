//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "MinesweeperEngine.hpp"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

void ANAL::MinesweeperEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    renderer.clear();
    this->_renderBackground(renderer, arcade);
    this->_renderCases(renderer, arcade);
    renderer.render();
}

void ANAL::MinesweeperEngine::_renderBackground(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const
{
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    asset->setTexturePath("./assets/minesweeper/hidden.png");
    asset->setAlternateRender('~');
    entity->setAsset(*asset);
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            entity->setPos({static_cast<int>(i), static_cast<int>(j)});
            renderer.drawEntity(*entity);
        }
    }
}

void ANAL::MinesweeperEngine::_renderCases(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade) const
{
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_hidden[i][j] == Visibility::HIDDEN)
                this->_displayHidden(renderer, arcade, i, j);
            if (this->_hidden[i][j] == Visibility::VISIBLE)
                this->_displayVisible(renderer, arcade, i, j);
            if (this->_hidden[i][j] == Visibility::FLAG)
                this->_displayFlag(renderer, arcade, i, j);
        }
    }
}

void ANAL::MinesweeperEngine::_displayHidden(ANAL::IRenderer &renderer,
    const ANAL::IArcade &arcade, size_t i, size_t j) const
{
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    asset->setTexturePath("./assets/minesweeper/hidden.png");
    asset->setAlternateRender('~');
    entity->setAsset(*asset);
    entity->setPos({static_cast<int>(i), static_cast<int>(j)});

    renderer.drawEntity(*entity);
}

void ANAL::MinesweeperEngine::_displayVisible(ANAL::IRenderer &renderer,
    const ANAL::IArcade &arcade, size_t i, size_t j) const
{

    std::stringstream pathStream;
    std::string path = "./assets/minesweeper/";
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    if (static_cast<uint8_t>(this->_map[i][j]) >= 1 &&
        static_cast<uint8_t>(this->_map[i][j]) <= 8) {
        pathStream << static_cast<uint8_t>(this->_map[i][j]);
        // std::cout << "Pathstream " << pathStream.rdbuf() << std::endl;
        pathStream >> path;
        asset->setAlternateRender(pathStream.str().front());
        std::cout << "Ici: " << path << std::endl;
    }
    if (this->_map[i][j] == Case::EMPTY) {
        path += "empty";
        asset->setAlternateRender(' ');
    }
    if (this->_map[i][j] == Case::MINE) {
        path += "bombe";
        asset->setAlternateRender('x');
    }
    path += ".png";
    asset->setTexturePath(path);
    entity->setAsset(*asset);
    entity->setPos({static_cast<int>(i), static_cast<int>(j)});

    renderer.drawEntity(*entity);
}

void ANAL::MinesweeperEngine::_displayFlag(ANAL::IRenderer &renderer,
    const ANAL::IArcade &arcade, size_t i, size_t j) const
{
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    asset->setTexturePath("assets/flag.png");
    asset->setAlternateRender(' ');
    entity->setAsset(*asset);
    entity->setPos({static_cast<int>(i), static_cast<int>(j)});

    renderer.drawEntity(*entity);
}

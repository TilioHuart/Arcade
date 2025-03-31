//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "MinesweeperEngine.hpp"

void ANAL::MinesweeperEngine::render(
    ANAL::IRenderer &renderer, ANAL::IArcade &arcade)
{
    renderer.clear();
    this->_renderBackground(renderer, arcade);
    renderer.render();
}

void ANAL::MinesweeperEngine::_renderBackground(
    ANAL::IRenderer &renderer, ANAL::IArcade &arcade) const
{
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    asset->setTexturePath("assets/hidden.png");
    asset->setAlternateRender(' ');
    entity->setAsset(*asset);
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            entity->setPos({static_cast<int>(i * (900 / this->_gridSize)),
                static_cast<int>(j * (900 / this->_gridSize))});
            renderer.drawEntity(*entity);
        }
    }
}

//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Render.cpp
//

#include "SnakeEngine.hpp"
#include <iostream>
#include <sstream>

void ANAL::SnakeEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    renderer.clear();
    if (this->gameState != VICTORY::UNDEFINED) {
        if (this->gameState == VICTORY::YES) {
            renderer.drawText("WIN", {16, 16});
            renderer.render();
            return;
        }
        if (this->gameState == VICTORY::NO) {
            renderer.drawText("LOOSE", {16, 16});
            renderer.render();
            return;
        }
    }
    this->renderMap(renderer, arcade);
    this->renderFruit(renderer, arcade);
    this->renderSnake(renderer, arcade);
    this->renderScore(renderer, arcade);
    renderer.render();
}

void ANAL::SnakeEngine::renderMap(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    auto assets = arcade.newAsset();
    auto entity = arcade.newEntity();
    assets->setTexturePath("./assets/snake/map.jpg");
    assets->setAlternateRender(' ');
    entity->setAsset(*assets);
    int i = 0;
    int j = 0;
    for (const auto &it : this->map) {
        for (auto elt : it) {
            entity->setPos({j, i});
            renderer.drawEntity(*entity);
            j += 1;
        }
        i += 1;
        j = 0;
    }
}

void ANAL::SnakeEngine::renderFruit(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    auto newAssets = arcade.newAsset();
    auto newEntity = arcade.newEntity();
    newAssets->setTexturePath("./assets/snake/apple.png");
    newAssets->setAlternateRender('P');
    newEntity->setAsset(*newAssets);
    newEntity->setPos({this->fruitX, this->fruitY});
    renderer.drawEntity(*newEntity);
}

void ANAL::SnakeEngine::renderSnake(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    auto newAssets = arcade.newAsset();
    auto newEntity = arcade.newEntity();
    newAssets->setTexturePath("./assets/snake/snakeBody.jpg");
    newAssets->setAlternateRender('B');
    newEntity->setAsset(*newAssets);
    for (const auto &it : this->snake) {
        newEntity->setPos({it.x, it.y});
        renderer.drawEntity(*newEntity);
    }
}

void ANAL::SnakeEngine::renderScore(ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    std::stringstream scoreStream;
    std::string scoreString ;
    scoreStream << this->score;
    scoreStream >> scoreString;
    renderer.drawText(scoreString.c_str(), {16, 2});
}

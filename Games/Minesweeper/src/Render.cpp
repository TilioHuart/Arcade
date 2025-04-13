//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "IRenderer.hpp"
#include "MinesweeperEngine.hpp"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

void ANAL::MinesweeperEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    if (this->_hasLose) {
        this->_displayLose(renderer, arcade);
        return;
    }
    if (this->_hasWin) {
        this->_displayWin(renderer, arcade);
        return;
    }
    renderer.clear();
    this->_renderBackground(renderer, arcade);
    this->_renderCases(renderer, arcade);
    this->_renderAth(renderer);
    renderer.render();
}

void ANAL::MinesweeperEngine::_renderAth(ANAL::IRenderer &renderer)
{
    auto minesLefts = this->_nbMine - this->_nbFlags;
    std::stringstream minesLeftStream;
    std::string minesLeftStr;

    std::stringstream scoreStream;
    std::string scoreStr;

    std::stringstream timeLeftStream;
    std::string timeLeftStr;

    if (this->_firstClick) {
        this->_endTime = std::chrono::steady_clock::now() +
                         std::chrono::seconds(this->_nbMine * 10);
    }
    std::chrono::duration<double> timeLeft =
        this->_endTime - std::chrono::steady_clock::now();
    if (timeLeft.count() <= 0) {
        this->_hasLose = true;
    }

    minesLeftStream << minesLefts;
    minesLeftStream >> minesLeftStr;

    scoreStream << this->_score;
    scoreStream >> scoreStr;

    timeLeftStream << (timeLeft.count() < 0 ? 0 : timeLeft.count());
    timeLeftStream >> timeLeftStr;

    renderer.drawText("Mines left: " + minesLeftStr, {23, 1});
    renderer.drawText("Score: " + scoreStr, {1, 23});
    if (!this->_hasWin && !this->_hasLose)
        renderer.drawText("Time: " + timeLeftStr, {23, 23});
}

void ANAL::MinesweeperEngine::_displayLose(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    this->_displayMines(renderer, arcade);

    renderer.clear();
    this->_renderAth(renderer);
    renderer.drawText("You Lose", Vector2<int>(10, 10));
    renderer.render();
}

void ANAL::MinesweeperEngine::_displayWin(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    renderer.clear();
    this->_renderAth(renderer);
    renderer.drawText("You Win", Vector2<int>(10, 10));
    renderer.render();
}

void ANAL::MinesweeperEngine::_displayMines(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    if (this->_mineDisplayed)
        return;
    for (size_t i = 0; i < this->_gridSize; i += 1) {
        for (size_t j = 0; j < this->_gridSize; j += 1) {
            if (this->_map[i][j] == Case::MINE) {
                this->_hidden[i][j] = ANAL::Visibility::VISIBLE;
            }
        }
    }
    renderer.clear();
    this->_renderBackground(renderer, arcade);
    this->_renderCases(renderer, arcade);
    this->_renderAth(renderer);
    renderer.render();
    this->_mineDisplayed = true;

    auto timeToWait = std::chrono::milliseconds(3000);
    std::this_thread::sleep_for(timeToWait);
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
    std::string tmp;
    auto entity = arcade.newEntity();
    auto asset = arcade.newAsset();

    if (static_cast<uint8_t>(this->_map[i][j]) >= 1 &&
        static_cast<uint8_t>(this->_map[i][j]) <= 8) {
        pathStream << static_cast<int>(this->_map[i][j]);
        pathStream >> tmp;
        path += tmp;
        asset->setAlternateRender(tmp.front());
    } else if (this->_map[i][j] == Case::EMPTY) {
        pathStream << "empty";
        pathStream >> tmp;
        path += tmp;
        asset->setAlternateRender('0');
    } else if (this->_map[i][j] == Case::MINE) {
        pathStream << "bombe";
        pathStream >> tmp;
        path += tmp;
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

    asset->setTexturePath("assets/minesweeper/flag.png");
    asset->setAlternateRender('?');
    entity->setAsset(*asset);
    entity->setPos({static_cast<int>(i), static_cast<int>(j)});

    renderer.drawEntity(*entity);
}

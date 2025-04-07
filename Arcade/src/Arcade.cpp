//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Arcade.hpp"
#include "Asset.hpp"
#include "Entity.hpp"
#include "Events.hpp"
#include "IGame.hpp"
#include "src/DlUtils.hpp"
#include "src/Menu.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void Arcade::Arcade::setGame(std::unique_ptr<ANAL::IGame> &newGame)
{
    if (newGame == nullptr) {
        throw Arcade::Arcade::ArcadeError("GameEngine is null");
    }
    this->_runningGame = std::move(newGame);
}

void Arcade::Arcade::setDisplay(std::unique_ptr<ANAL::IRenderer> &newDisplay)
{
    if (newDisplay == nullptr) {
        throw Arcade::Arcade::ArcadeError("DisplayRenderer is null");
    }
    this->_runningDisplay = std::move(newDisplay);
}

void Arcade::Arcade::run()
{
    std::vector<ANAL::Event> events;

    while (this->_isRunning) {
        auto frameStart = std::chrono::steady_clock::now();

        this->_runningGame->render(*this->_runningDisplay, *this);
        auto *menu = dynamic_cast<MenuEngine*>(this->_runningGame.get());

        if (menu != nullptr) {
            this->_gameToLaunch = menu->getGame();
            this->_rendererToLaunch = menu->getRenderer();
            this->_reloadRenderer();
            this->_reloadGame();
        }

        events.clear();
        events = this->_runningDisplay->getEvents();
        for (const auto &event : events) {
            if (event.closeEvent) {
                this->_isRunning = false;
                break;
            }
        }
        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);
        const std::chrono::milliseconds targetFrameDuration(50);
        if (frameDuration < targetFrameDuration) {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
        this->_runningGame->processEvents(events);
        this->_runningGame->compute();
    }
}

void Arcade::Arcade::setGameToLaunch(const std::string &gameToLaunch)
{
    this->_gameToLaunch = gameToLaunch;
}

void Arcade::Arcade::setRendererToLaunch(const std::string &rendererToLaunch)
{
    this->_rendererToLaunch = rendererToLaunch;
}

void Arcade::Arcade::_reloadRenderer()
{
    auto rendererLib = this->_rendererToLaunch;

    if (rendererLib == "")
        return;
    void *loadedLib = DlUtils::open(rendererLib);
    auto graphical = DlUtils::loadDisplay(loadedLib);

    this->setDisplay(graphical);
    this->_rendererToLaunch = "";
}

void Arcade::Arcade::_reloadGame()
{
    auto gameLib = this->_gameToLaunch;

    if (gameLib == "")
        return;
    void *loadedGame = DlUtils::open(gameLib);
    auto game = DlUtils::loadGame(loadedGame);

    this->setGame(game);
    this->_gameToLaunch = "";
}

[[nodiscard]] std::unique_ptr<ANAL::IAsset> Arcade::Arcade::newAsset() const
{
    return std::make_unique<ANAL::Asset>();
}

[[nodiscard]] std::unique_ptr<ANAL::IEntity> Arcade::Arcade::newEntity() const
{
    return std::make_unique<ANAL::Entity>();
}

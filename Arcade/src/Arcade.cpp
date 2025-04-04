//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Arcade.hpp"
#include "Asset.hpp"
#include "Entity.hpp"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

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
    while (this->_isRunning) {
        auto frameStart = std::chrono::steady_clock::now();

        this->_runningGame->render(*this->_runningDisplay, *this);

        auto events = this->_runningDisplay->getEvents();
        for (const auto &event : events) {
            if (event.closeEvent) {
                this->_isRunning = false;
                continue;
            }
        }
        std::cout << "Hello there" << std::endl;

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);
        const std::chrono::milliseconds targetFrameDuration(500);
        if (frameDuration < targetFrameDuration) {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }

        this->_runningGame->processEvents(events);
        this->_runningGame->compute();
    }
}

[[nodiscard]] std::unique_ptr<ANAL::IAsset> Arcade::Arcade::newAsset() const
{
    return std::make_unique<ANAL::Asset>();
}

[[nodiscard]] std::unique_ptr<ANAL::IEntity> Arcade::Arcade::newEntity() const
{
    return std::make_unique<ANAL::Entity>();
}

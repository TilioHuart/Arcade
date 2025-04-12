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
#include "IModule.hpp"
#include "src/DlUtils.hpp"
#include "src/Menu.hpp"
#include <chrono>
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <thread>
#include <vector>

Arcade::Arcade::Arcade(const std::string &renderer)
    : _score(0), _playerName("Moi")
{
    this->_loadedGraphicalLib = DlUtils::open(renderer);
    if (DlUtils::getLibType(this->_loadedGraphicalLib) !=
        ANAL::ModuleType::RENDERER) {
        DlUtils::close(this->_loadedGraphicalLib);
        throw DlUtils::DlUtilsError("not a graphical library");
    }
    auto graphical = DlUtils::loadDisplay(this->_loadedGraphicalLib);

    this->setDisplay(graphical);
}

Arcade::Arcade::~Arcade()
{
    this->_runningDisplay.reset();
    this->_runningGame.reset();

    if (this->_loadedGameLib != nullptr) {
        DlUtils::close(this->_loadedGameLib);
        this->_loadedGameLib = nullptr;
    }
    if (this->_loadedGraphicalLib != nullptr) {
        DlUtils::close(this->_loadedGraphicalLib);
        this->_loadedGraphicalLib = nullptr;
    }
}

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

        auto *menu = dynamic_cast<MenuEngine *>(this->_runningGame.get());

        if (menu != nullptr) {
            this->_gameToLaunch = menu->getGame();
            this->_rendererToLaunch = menu->getRenderer();
            this->_reloadRenderer();
            this->_reloadGame();
        }

        events.clear();
        events = this->_runningDisplay->getEvents();
        if (!this->_processArcadeEvents(events)) {
            events.clear();
            continue;
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
        this->_runningGame->compute(*this);
    }
}

bool Arcade::Arcade::_processArcadeEvents(
    const std::vector<ANAL::Event> &events)
{
    for (const auto &event : events) {
        if (event.closeEvent) {
            this->_isRunning = false;
            return false;
        }
        if (event.keyEvent->key == ANAL::Keys::KEY_Q &&
            event.keyEvent->state == ANAL::State::PRESSED) {
            this->_isRunning = false;
            return false;
        }
        if (event.keyEvent->key == ANAL::Keys::KEY_P &&
            event.keyEvent->state == ANAL::State::PRESSED) {
            this->_getNextGame();
            this->_reloadGame();
        }
        if (event.keyEvent->key == ANAL::Keys::KEY_M &&
            event.keyEvent->state == ANAL::State::PRESSED) {
            this->_getNextGraphical();
            this->_reloadRenderer();
        }
        if (event.keyEvent->key == ANAL::Keys::KEY_R &&
            event.keyEvent->state == ANAL::State::PRESSED) {
            this->_gameToLaunch = this->_savedGame;
            this->_reloadGame();
        }
        if (event.keyEvent->key == ANAL::Keys::KEY_N &&
            event.keyEvent->state == ANAL::State::PRESSED) {
            std::unique_ptr<ANAL::IGame> menu = std::make_unique<MenuEngine>();
            this->setGame(menu);
            return false;
        }
    }
    return true;
}

void Arcade::Arcade::_getNextGame()
{
    std::string gameToLoad;
    bool isNext = false;

    for (const auto &elem : std::filesystem::directory_iterator("./lib")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            void *lib = DlUtils::open(elem.path().string());
            ANAL::ModuleType type = DlUtils::getLibType(lib);
            DlUtils::close(lib);
            switch (type) {
                case ANAL::ModuleType::GAME:
                    if (gameToLoad.empty() || isNext) {
                        gameToLoad = elem.path().string();
                        isNext = false;
                    }
                    if (gameToLoad == this->_savedGame) {
                        isNext = true;
                    }
                    break;
                default:
                    break;
            }
        } catch (const DlUtils::DlUtilsError &) {
            continue;
        }
    }
    this->_gameToLaunch = gameToLoad;
}

void Arcade::Arcade::_getNextGraphical()
{
    std::string graphicalToLoad;
    std::string current;
    bool isNext = false;

    for (const auto &elem : std::filesystem::directory_iterator("./lib")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            void *lib = DlUtils::open(elem.path().string());
            ANAL::ModuleType type = DlUtils::getLibType(lib);
            DlUtils::close(lib);
            switch (type) {
                case ANAL::ModuleType::RENDERER:
                    current = elem.path().string();
                    if (graphicalToLoad.empty() || isNext) {
                        graphicalToLoad = current;
                        isNext = false;
                    }
                    if (current == this->_savedRenderer) {
                        isNext = true;
                    }
                    break;
                default:
                    break;
            }
        } catch (const DlUtils::DlUtilsError &) {
            continue;
        }
    }
    this->_rendererToLaunch = graphicalToLoad;
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

    if (rendererLib.empty())
        return;

    this->_runningDisplay.reset();
    if (this->_loadedGraphicalLib != nullptr) {
        DlUtils::close(this->_loadedGraphicalLib);
        this->_loadedGraphicalLib = nullptr;
    }

    this->_loadedGraphicalLib = DlUtils::open(rendererLib);
    auto graphical = DlUtils::loadDisplay(this->_loadedGraphicalLib);

    this->setDisplay(graphical);
    this->_savedRenderer = rendererLib;
    this->_rendererToLaunch.clear();
}

void Arcade::Arcade::_reloadGame()
{
    auto gameLib = this->_gameToLaunch;

    if (gameLib.empty())
        return;

    this->_runningGame.reset();
    if (this->_loadedGameLib != nullptr) {
        DlUtils::close(this->_loadedGameLib);
        this->_loadedGameLib = nullptr;
    }

    this->_loadedGameLib = DlUtils::open(gameLib);
    auto game = DlUtils::loadGame(this->_loadedGameLib);

    this->setGame(game);
    this->_savedGame = gameLib;
    this->_gameToLaunch.clear();
}

const std::string &Arcade::Arcade::getPlayerName() const
{
    return this->_playerName;
}

void Arcade::Arcade::setPlayerHighscore(int score)
{
    this->_score = score;
}

int Arcade::Arcade::getPlayerHighscore(const std::string &playerName) const
{
    return this->_score;
}

[[nodiscard]] std::unique_ptr<ANAL::IAsset> Arcade::Arcade::newAsset() const
{
    return std::make_unique<ANAL::Asset>();
}

[[nodiscard]] std::unique_ptr<ANAL::IEntity> Arcade::Arcade::newEntity() const
{
    return std::make_unique<ANAL::Entity>();
}

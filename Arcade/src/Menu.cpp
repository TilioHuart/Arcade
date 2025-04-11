//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Menu.hpp"
#include "DlUtils.hpp"
#include "Events.hpp"
#include "IArcade.hpp"
#include "IGame.hpp"
#include "IModule.hpp"
#include "IRenderer.hpp"
#include "Vector2.hpp"
#include "src/Arcade.hpp"
#include "src/DlUtils.hpp"
#include <filesystem>
#include <iostream>
#include <memory>
#include <ostream>

Arcade::MenuEngine::MenuEngine()
{
    this->_actualGame = 0;
    this->_actualRenderer = 0;
    this->_launchGame = false;
    for (const auto &elem : std::filesystem::directory_iterator("./lib")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            void *lib = DlUtils::open(elem.path().string());
            ANAL::ModuleType type = DlUtils::getLibType(lib);
            DlUtils::close(lib);
            switch (type) {
                case ANAL::ModuleType::GAME:
                    this->_games.push_back(elem.path().string());
                    break;
                case ANAL::ModuleType::RENDERER:
                    this->_renderers.push_back(elem.path().string());
                    break;
                default:
                    break;
            }
        } catch (const DlUtils::DlUtilsError &) {
            continue;
        }
    }
}

void Arcade::MenuEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    int line = 3;
    renderer.clear();
    renderer.setWindowTitle("uwu Menu");
    renderer.drawText("uwu_MENU_uwu", ANAL::Vector2<int>(3, 1));
    renderer.drawText("Games:", ANAL::Vector2<int>(0, line));
    renderer.drawText(">", ANAL::Vector2<int>(1, line + 1 + this->_actualGame));
    for (int i = 0; i < this->_games.size() && i < 10; i++) {
        line += 1;
        renderer.drawText(this->_games[i], ANAL::Vector2<int>(2, line));
    }
    line += 3;
    renderer.drawText("Displays:", ANAL::Vector2<int>(0, line));
    renderer.drawText(
        ">", ANAL::Vector2<int>(1, line + 1 + this->_actualRenderer));
    for (int i = 0; i < this->_renderers.size() && i < 10; i++) {
        line += 1;
        renderer.drawText(this->_renderers[i], ANAL::Vector2<int>(2, line));
    }
    renderer.render();
}

void Arcade::MenuEngine::compute(ANAL::IArcade &arcade) {}

void Arcade::MenuEngine::processEvents(std::vector<ANAL::Event> &Event)
{
    for (const auto &elem : Event) {
        if (elem.keyEvent->key == ANAL::Keys::KEY_H &&
            this->_actualGame < this->_games.size() - 1 &&
            elem.keyEvent->state == ANAL::State::RELEASED) {
            this->_actualGame += 1;
        }
        if (elem.keyEvent->key == ANAL::Keys::KEY_J && this->_actualGame > 0 &&
            elem.keyEvent->state == ANAL::State::RELEASED) {
            this->_actualGame -= 1;
        }
        if (elem.keyEvent->key == ANAL::Keys::KEY_K &&
            this->_actualRenderer < this->_renderers.size() - 1 &&
            elem.keyEvent->state == ANAL::State::RELEASED) {
            this->_actualRenderer += 1;
        }
        if (elem.keyEvent->key == ANAL::Keys::KEY_L &&
            this->_actualRenderer > 0 &&
            elem.keyEvent->state == ANAL::State::RELEASED) {
            this->_actualRenderer -= 1;
        }
        if (elem.keyEvent->key == ANAL::Keys::KEY_E &&
            elem.keyEvent->state == ANAL::State::RELEASED)
            this->_launchGame = true;
    }
}

std::string Arcade::MenuEngine::getGame() {
    return _launchGame ? _games[_actualGame] : "";
}

std::string Arcade::MenuEngine::getRenderer() {
    return _launchGame ? _renderers[_actualRenderer] : "";
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::GAME;
}

std::unique_ptr<ANAL::IGame> uwu_entrypoint_game(void)
{
    return std::make_unique<Arcade::MenuEngine>();
}
}

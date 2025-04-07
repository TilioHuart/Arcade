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
#include "src/DlUtils.hpp"
#include <filesystem>
#include <filesystem>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

Arcade::MenuEngine::MenuEngine()
{
    this->retrieveModules();
}

void Arcade::MenuEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    int pos = 3;
    renderer.clear();
    renderer.setWindowTitle("uwu Menu");
    renderer.drawText("uwu_MENU_uwu", ANAL::Vector2<int>(3, 1));
    renderer.drawText("Games:", ANAL::Vector2<int>(0, pos));
    pos += 2;
    for (const auto &it : this->_games) {
        if (it.second)
            renderer.drawText(it.first + " *", ANAL::Vector2<int>(1, pos));
        else
            renderer.drawText(it.first, ANAL::Vector2<int>(1, pos));
        pos += 3;
    }
    renderer.drawText("Displays:", ANAL::Vector2<int>(0, 6));
    for (const auto &it : this->_renderer) {
        if (it.second)
            renderer.drawText(it.first + " *", ANAL::Vector2<int>(1, pos));
        else
            renderer.drawText(it.first, ANAL::Vector2<int>(1, pos));
        pos += 3;
    }
    renderer.render();
}

void Arcade::MenuEngine::compute() {
    std::string currPath = std::filesystem::current_path();
    for (const auto &elem : std::filesystem::directory_iterator(currPath + "/lib")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            void *lib = Arcade::DlUtils::open(elem.path().string());
            ANAL::ModuleType type = Arcade::DlUtils::getLibType(lib);
            switch (type) {
                case ANAL::ModuleType::GAME:
                    this->_games.push_back(std::make_pair(elem.path().string(), false));
                    break;
                case ANAL::ModuleType::RENDERER:
                    this->_renderer.push_back(std::make_pair(elem.path().string(), false));
                    break;
                default:
                    break;
            }
        }
        catch (const DlUtils::DlUtilsError&) {
            continue;
        }
    }
}

void Arcade::MenuEngine::processEvents(std::vector<ANAL::Event> &Event)
{
}

void Arcade::MenuEngine::retrieveModules()
{
    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        std::cout << entry.path() << std::endl;
        void *lib = Arcade::DlUtils::open(entry.path());
        if (Arcade::DlUtils::getLibType(lib) == ANAL::ModuleType::GAME)
            this->_games.push_back(std::make_pair(entry.path(), false));
        if (Arcade::DlUtils::getLibType(lib) == ANAL::ModuleType::RENDERER)
            this->_renderer.push_back(std::make_pair(entry.path(), false));
    }
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

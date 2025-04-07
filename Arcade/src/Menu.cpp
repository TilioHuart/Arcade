//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Menu.hpp"
#include "IArcade.hpp"
#include "IGame.hpp"
#include "IModule.hpp"
#include "IRenderer.hpp"
#include "Vector2.hpp"
#include "src/DlUtils.hpp"
#include <filesystem>
#include <memory>

void Arcade::MenuEngine::render(
    ANAL::IRenderer &renderer, const ANAL::IArcade &arcade)
{
    int line = 0;
    renderer.clear();
    renderer.setWindowTitle("uwu Menu");
    renderer.drawText("uwu_MENU_uwu", ANAL::Vector2<int>(3, line));
    line += 2;
    renderer.drawText("Games:", ANAL::Vector2<int>(0, line));
    for (int i = 0; i < this->_games.size() && i < 10; i++) {
        line += 1;
        renderer.drawText(this->_games[i], ANAL::Vector2<int>(2, line));
    }
    line += 3;
    renderer.drawText("Displays:", ANAL::Vector2<int>(0, line));
    for (int i = 0; i < this->_games.size() && i < 10; i++) {
        line += 1;
        renderer.drawText(this->_renderers[i], ANAL::Vector2<int>(2, line));
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
                    this->_games.push_back(elem.path().string());
                    break;
                case ANAL::ModuleType::RENDERER:
                    this->_renderers.push_back(elem.path().string());
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

//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.cpp
//

#include "DlUtils.hpp"
#include "IGame.hpp"
#include "IModule.hpp"
#include "dlfcn.h"
#include <string>

Arcade::DlUtils::DlUtilsError::DlUtilsError(std::string msg) : _msg(std::move(msg)) {}

void Arcade::DlUtils::open(const std::string &pathToLib)
{
    this->_lib = dlopen(pathToLib.c_str(), RTLD_LAZY);
    if (_lib == nullptr)
        throw DlUtilsError("Invalid pointer from dlopen");
}

void Arcade::DlUtils::close()
{
    if (_lib == nullptr || dlclose(this->_lib) != 0)
        throw DlUtilsError("Invalid lib can't be dlclosed");
}

ANAL::ModuleType Arcade::DlUtils::getLibType()
{
    auto *const func = reinterpret_cast<ANAL::ModuleType(*)()>
        (dlsym(this->_lib, "uwu_get_module_type"));
    if (func == nullptr)
        throw DlUtilsError("Couldn't retrieve lib type");
    return func();
}

std::unique_ptr<ANAL::IGame> Arcade::DlUtils::loadGame()
{
    const auto func = reinterpret_cast<std::unique_ptr<ANAL::IGame>(*)()>
        (dlsym(this->_game, "uwu_entrypoint_game"));
    if (func == nullptr)
        throw DlUtilsError("Couldn't retrieve game");
    auto game = func();
    return std::move(game);
}

std::unique_ptr<ANAL::IRenderer> Arcade::DlUtils::loadDisplay()
{
    const auto func = reinterpret_cast<std::unique_ptr<ANAL::IRenderer>(*)()>
        (dlsym(this->_display, "uwu_entrypoint_renderer"));
    if (func == nullptr)
        throw DlUtilsError("Couldn't retrieve display");
    auto renderer = func();
    return std::move(renderer);

}

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

void *Arcade::DlUtils::open(const std::string &pathToLib)
{
    void *lib = dlopen(pathToLib.c_str(), RTLD_LAZY);
    if (lib == nullptr)
        throw DlUtilsError("Invalid pointer from dlopen");
    return lib;
}

void Arcade::DlUtils::close(void *lib)
{
    if (lib == nullptr || dlclose(lib) != 0)
        throw DlUtilsError("Invalid lib can't be dlclosed");
}

ANAL::ModuleType Arcade::DlUtils::getLibType(void *lib)
{
    auto *const module = reinterpret_cast<ANAL::ModuleType(*)()>
        (dlsym(lib, "uwu_get_module_type"));
    if (module == nullptr)
        throw DlUtilsError("Couldn't retrieve lib type");
    return module();
}

std::unique_ptr<ANAL::IGame> Arcade::DlUtils::loadGame(void *lib)
{
    const auto module = reinterpret_cast<std::unique_ptr<ANAL::IGame>(*)()>
        (dlsym(lib, "uwu_entrypoint_game"));
    if (module == nullptr)
        throw DlUtilsError("Couldn't retrieve game");
    auto game = module();
    return std::move(game);
}

std::unique_ptr<ANAL::IRenderer> Arcade::DlUtils::loadDisplay(void *lib)
{
    const auto module = reinterpret_cast<std::unique_ptr<ANAL::IRenderer>(*)()>
        (dlsym(lib, "uwu_entrypoint_renderer"));
    if (module == nullptr)
        throw DlUtilsError("Couldn't retrieve display");
    auto renderer = module();
    return std::move(renderer);

}

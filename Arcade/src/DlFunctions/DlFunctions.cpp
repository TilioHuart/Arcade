//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.cpp
//

#include "DlFunctions.hpp"
#include "IRenderer.hpp"
#include "dlfcn.h"
#include <memory>
#include <string>

void Arcade::DlFunctions::loadLib(const std::string &pathToLib)
{
    this->_lib = dlopen(pathToLib.c_str(), RTLD_LAZY);
    if (_lib == nullptr)
        throw Error("Error dlopen");
}

std::unique_ptr<ANAL::IRenderer> Arcade::DlFunctions::callGraphicLib()
{
}

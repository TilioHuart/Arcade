//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.cpp
//

#include "DlFunctions.hpp"
#include "IRenderer.hpp"
#include "dlfcn.h"
#include "src/Arcade.hpp"
#include <memory>
#include <string>

Arcade::DlUtils::DlUtilsError::DlUtilsError(std::string msg) : _msg(std::move(msg)) {}

void Arcade::DlUtils::loadLib(const std::string &pathToLib)
{
    this->_lib = dlopen(pathToLib.c_str(), RTLD_LAZY);
    if (_lib == nullptr)
        throw DlUtilsError("Invalid pointer from dlopen");
}

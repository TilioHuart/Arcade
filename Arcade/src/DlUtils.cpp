//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.cpp
//

#include "DlUtils.hpp"
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

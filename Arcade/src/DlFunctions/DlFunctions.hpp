//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.hpp
//

#pragma once

#include "IRenderer.hpp"
#include <memory>
#include <string>

namespace Arcade {
    class DlFunctions {
       public:
        class Error : public std::exception {
           public:
            Error(std::string msg) : _msg(std::move(msg)) {};

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

        void loadLib(const std::string &pathToLib);
        std::unique_ptr<ANAL::IRenderer> callGraphicLib();

       private:
        void *_lib;
    };

}  // namespace Arcade

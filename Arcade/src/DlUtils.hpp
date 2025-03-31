//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// DlFunctions.hpp
//

#pragma once

#include "IGame.hpp"
#include "IModule.hpp"
#include "IRenderer.hpp"
#include <memory>
#include <string>

namespace Arcade {
    class DlUtils {
       public:
        class DlUtilsError : public std::exception {
           public:
            DlUtilsError(std::string msg);

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

        void open(const std::string &pathToLib);
        void close();
        ANAL::ModuleType getLibType();
        std::unique_ptr<ANAL::IGame> loadGame();
        std::unique_ptr<ANAL::IRenderer> loadDisplay();

       private:
        void *_lib;
        ANAL::IGame *_game;
        ANAL::IRenderer *_display;
    };

}  // namespace Arcade

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

        static void *open(const std::string &pathToLib);
        static void close(void *lib);
        static ANAL::ModuleType getLibType(void *lib);
        static std::unique_ptr<ANAL::IGame> loadGame(void *lib);
        static std::unique_ptr<ANAL::IRenderer> loadDisplay(void *lib);
    };

}  // namespace Arcade

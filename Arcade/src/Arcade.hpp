//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#pragma once

#include "IGame.hpp"
#include "IRenderer.hpp"
#include <string>
#include <vector>

namespace Arcade {
    class Arcade {
       public:
        Arcade() = default;
        ~Arcade() = default;

        void setGame(std::unique_ptr<ANAL::IGame> &);
        void setDisplay(std::unique_ptr<ANAL::IRenderer> &);

       private:
        std::unique_ptr<ANAL::IGame> _runningGame;
        std::unique_ptr<ANAL::IRenderer> _runningDisplay;
        std::vector<std::string> gameLibList;
        std::vector<std::string> displayLibList;
    };
}  // namespace Arcade

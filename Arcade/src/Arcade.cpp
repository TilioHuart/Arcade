//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Arcade.hpp"
#include "src/DlUtils.hpp"

void Arcade::Arcade::setGame(std::unique_ptr<ANAL::IGame> &newGame) {
    this ->_runningGame = std::move(newGame);
}

void Arcade::Arcade::setDisplay(std::unique_ptr<ANAL::IRenderer> &newDisplay) {
    this ->_runningDisplay = std::move(newDisplay);
}

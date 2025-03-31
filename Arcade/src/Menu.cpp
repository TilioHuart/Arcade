//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// Arcade
//

#include "Menu.hpp"
#include "IArcade.hpp"
#include "IRenderer.hpp"
#include "Vector2.hpp"

void Arcade::MenuEngine::render(ANAL::IRenderer &Display, ANAL::IArcade &Core)
{
    Display.clear();
    Display.setWindowTitle("uwu Menu");
    Display.drawText("uwu_MENU_uwu", ANAL::Vector2<int>(3, 1));
    Display.drawText("Games:", ANAL::Vector2<int>(0, 3));
    Display.drawText("Displays:", ANAL::Vector2<int>(0, 6));
    Display.render();
}

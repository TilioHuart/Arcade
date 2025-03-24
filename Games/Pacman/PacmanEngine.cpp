//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// PacmanEngine.cpp
//

#include "PacmanEngine.hpp"
#include "IRenderer.hpp"

void game::PacmanEngine::processEvents(const std::vector<ANAL::Event> &event)
{

}

void game::PacmanEngine::render(ANAL::IRenderer& renderer)
{
    if (this->getSprite().empty())
        return;
    for (auto it : this->getSprite())
        renderer.drawSprite(*it);
    renderer.render();
    renderer.clear();
}

void game::PacmanEngine::compute()
{

}

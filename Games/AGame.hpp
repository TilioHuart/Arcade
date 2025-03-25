//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// AGame.hpp
//

#pragma once

#include "Events.hpp"
#include "IArcade.hpp"
#include "IGame.hpp"
#include "IRenderer.hpp"
#include "ISprite.hpp"
#include <memory>
#include <vector>

namespace ANAL {
    class AGame : public ANAL::IGame {
       public:
        void processEvents(std::vector<Event>& Event) override;
        void compute() override;
        void render(ANAL::IRenderer &renderer, ANAL::IArcade& arcade) override;
    };

}  // namespace ANAL

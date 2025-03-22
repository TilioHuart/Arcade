//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// AGame.hpp
//

#pragma once

#include "Events.hpp"
#include "IGame.hpp"

namespace game {
    class AGame : public ANAL::IGame {
       public:
        virtual void processEvents(const std::vector<ANAL::Event> &) = 0;
        virtual void compute() = 0;
        virtual void render() override;
       protected:
    };

}  // namespace game

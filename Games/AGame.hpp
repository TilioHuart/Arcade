//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// AGame.hpp
//

#pragma once

#include "Events.hpp"
#include "IGame.hpp"
#include "IRenderer.hpp"
#include "ISprite.hpp"
#include <list>
#include <memory>

namespace game {
    class AGame : public ANAL::IGame {
       public:
        void processEvents(const std::vector<ANAL::Event> &event) override = 0;
        void compute() override = 0;
        void render(ANAL::IRenderer& renderer) override = 0;

       protected:
        void setSprite(ANAL::ISprite &sprite)
        {
            this->_sprites.push_back(std::make_shared<ANAL::ISprite>(sprite));
        }

        std::list<std::shared_ptr<ANAL::ISprite>> getSprite() const
        {
            return this->_sprites;
        }

       private:
        std::list<std::shared_ptr<ANAL::ISprite>> _sprites;
    };

}  // namespace game

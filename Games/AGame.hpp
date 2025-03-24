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
#include <memory>
#include <vector>

namespace game {
    class AGame : public ANAL::IGame {
       public:
        void processEvents(const std::vector<ANAL::Event> &event) override = 0;
        void compute() override = 0;
        void render(ANAL::IRenderer &renderer) override = 0;

       protected:
        virtual void setSprite(ANAL::ISprite &sprite);

        [[nodiscard]] std::vector<std::shared_ptr<ANAL::ISprite>>
        getSprite() const;

       private:
        std::vector<std::shared_ptr<ANAL::ISprite>> _sprites;
    };

}  // namespace game

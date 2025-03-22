//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// ASprite
//

#pragma once

#include "IAsset.hpp"
#include "ISprite.hpp"
#include "Vector2.hpp"

namespace sprite {
    class ASprite : public ANAL::ISprite {
       public:
        ANAL::Vector2<int> getPos() override { return this->pos; }

        void setPos(ANAL::Vector2<int> vecPos) override { this->pos = vecPos; }

        ANAL::IAsset getAsset() override { return this->asset; }

        void setAsset(ANAL::IAsset asset) override { this->asset = asset; }
       private:
        ANAL::Vector2<int> pos;
        ANAL::IAsset asset;
    };

}  // namespace sprite

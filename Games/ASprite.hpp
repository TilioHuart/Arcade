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
#include <memory>

namespace sprite {
    class ASprite : public ANAL::ISprite {
       public:
        ANAL::Vector2<int> getPos() override { return this->_pos; }

        void setPos(ANAL::Vector2<int> vecPos) override { this->_pos = vecPos; }

        ANAL::IAsset &getAsset() override { return *this->_asset; }

        void setAsset(ANAL::IAsset &asset) override
        {
            this->_asset = std::make_shared<ANAL::IAsset>(asset);
        }

       private:
        ANAL::Vector2<int> _pos;
        std::shared_ptr<ANAL::IAsset> _asset = nullptr;
    };

}  // namespace sprite

//
// EPITECH PROJECT, 2025
// Entity
// File description:
// Entity
//

#pragma once

#include "Asset.hpp"
#include "IAsset.hpp"
#include "IEntity.hpp"
#include "Vector2.hpp"
#include <memory>

namespace ANAL {
    class Entity : public ANAL::IEntity {
       public:
        ~Entity() override = default;

        void setPos(Vector2<int> positions) override
        {
            this->_pos = positions;
        };

        [[nodiscard]] const Vector2<int> &getPos() const override
        {
            return this->_pos;
        };

        void setAsset(IAsset &asset) override { this->_asset = Asset(); };  // à modifier

        [[nodiscard]] const Asset &getAsset() const override { return this->_asset; };

        std::unique_ptr<IEntity> clone() const
        {
            return std::make_unique<Entity>(*this);
        };

       private:
        Vector2<int> _pos;
        Asset _asset;
    };
}  // namespace ANAL

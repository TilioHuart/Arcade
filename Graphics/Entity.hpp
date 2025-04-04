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
        Entity(): _pos(0, 0) {} ;
        Entity(const Entity &other) : _pos(other._pos)
        {
            const auto &asset =
                dynamic_cast<const Asset *>(other._asset.get());

            this->_asset = std::make_unique<ANAL::Asset>(*asset);
        }

        ~Entity() override = default;

        void setPos(const Vector2<int> &positions) override
        {
            this->_pos = positions;
        };

        [[nodiscard]] const Vector2<int> &getPos() const override
        {
            return this->_pos;
        };

        void setAsset(const IAsset &asset) override
        {
            this->_asset =
                std::make_unique<Asset>(static_cast<const Asset &>(asset));
        }

        [[nodiscard]] const IAsset &getAsset() const override
        {
            return *this->_asset;
        };

        std::unique_ptr<IEntity> clone() const
        {
            return std::make_unique<Entity>(*this);
        };

       private:
        Vector2<int> _pos;
        std::unique_ptr<IAsset> _asset = nullptr;
    };
}  // namespace ANAL

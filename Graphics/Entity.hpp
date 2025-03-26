//
// EPITECH PROJECT, 2025
// Entity
// File description:
// Entity
//

#pragma once

#include "IEntity.hpp"
#include "Asset.hpp"
#include "Vector2.hpp"

namespace ANAL {
    class Entity : public ANAL::IEntity {
       public:
        virtual ~Entity() = default;

        virtual void setPos(Vector2<int> positions)
        {
            this->_pos = positions;
        };

        [[nodiscard]] virtual Vector2<int> &getPos() { return this->_pos;};

        virtual void setAsset() {this->_asset = Asset();}; // à modifier

        [[nodiscard]] virtual const Asset &getAsset() const {return this->_asset;};

       private:
        Vector2<int> _pos;
        Asset _asset;
    };
}  // namespace ANAL

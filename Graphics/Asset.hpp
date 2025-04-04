//
// EPITECH PROJECT, 2025
// Asset
// File description:
// Asset
//

#pragma once

#include "IAsset.hpp"
#include <string>
#include <memory>

namespace ANAL {
    class Asset : public IAsset {
       public:
        Asset() = default;

        Asset(const Asset &asset) { *this = asset; }

        virtual ~Asset() = default;

        Asset &operator=(const Asset &asset)
        {
            this->_texturePath = asset._texturePath;
            this->_alt = asset._alt;
            return *this;
        }

        [[nodiscard]] std::unique_ptr<IAsset> clone() const
        {
            return std::make_unique<Asset>(*this);
        }

        void setTexturePath(const std::string &texture) final
        {
            this->_texturePath = texture;
        };

        [[nodiscard]] const std::string &getTexturePath() const final
        {
            return this->_texturePath;
        };

        void setAlternateRender(char alt) final { this->_alt = alt; };

        [[nodiscard]] char getAlternateRender() const final
        {
            return this->_alt;
        };

       private:
        std::string _texturePath;
        char _alt;
    };
}  // namespace ANAL

//
// EPITECH PROJECT, 2025
// Asset
// File description:
// Asset
//

#pragma once

#include "IAsset.hpp"
#include <string>

namespace ANAL {
    class Asset : public IAsset {
       public:
        Asset() = default;
        virtual ~Asset() = default;

        virtual void setTexturePath(const std::string &texture)
        {
            this->_texturePath = texture;
        };

        [[nodiscard]] virtual const std::string &getTexturePath() const
        {
            return this->_texturePath;
        };

        virtual void setAlternateRender(char alt) { this->_alt = alt; };

        [[nodiscard]] virtual char getAlternateRender() const
        {
            return this->_alt;
        };

       private:
        std::string _texturePath;
        char _alt;
    };
}  // namespace ANAL

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

/**
 * @class Asset
 * @brief Represents a concrete implementation of IAsset.
 *
 * This class manages graphical asset resources by allowing the texture path to be set and retrieved,
 * as well as an alternate render character.
 */
class Asset : public IAsset {
   public:
    /**
     * @brief Default constructor.
     */
    Asset() = default;

    /**
     * @brief Copy constructor.
     * @param asset The Asset instance to copy from.
     */
    Asset(const Asset &asset) { *this = asset; }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Asset() = default;

    /**
     * @brief Assignment operator.
     *
     * Copies the texture path and the alternate render character from another asset.
     *
     * @param asset The asset to copy.
     * @return A reference to the copied asset.
     */
    Asset &operator=(const Asset &asset)
    {
        this->_texturePath = asset._texturePath;
        this->_alt = asset._alt;
        return *this;
    }

    /**
     * @brief Clones the current asset.
     *
     * Creates and returns a copy of the current asset.
     *
     * @return A unique pointer to the cloned asset.
     */
    [[nodiscard]] std::unique_ptr<IAsset> clone() const
    {
        return std::make_unique<Asset>(*this);
    }

    /**
     * @brief Sets the texture path for the asset.
     *
     * @param texture A string representing the file path to the texture.
     */
    void setTexturePath(const std::string &texture) final
    {
        this->_texturePath = texture;
    }

    /**
     * @brief Retrieves the texture path of the asset.
     *
     * @return A constant reference to the texture path string.
     */
    [[nodiscard]] const std::string &getTexturePath() const final
    {
        return this->_texturePath;
    }

    /**
     * @brief Sets the alternate render character for the asset.
     *
     * @param alt The character used as the alternate render.
     */
    void setAlternateRender(char alt) final { this->_alt = alt; }

    /**
     * @brief Retrieves the alternate render character for the asset.
     *
     * @return The alternate render character.
     */
    [[nodiscard]] char getAlternateRender() const final
    {
        return this->_alt;
    };

   private:
    std::string _texturePath; ///< The texture path associated with the asset.
    char _alt;                ///< The alternate render character.
};

}  // namespace ANAL

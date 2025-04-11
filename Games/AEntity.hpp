//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// AEntity.hpp
//

#include "IAsset.hpp"
#include "IEntity.hpp"

namespace ANAL {
    class AEntity : public ANAL::IEntity {
       public:
        void setPos(const Vector2<int> &pos) override;

        [[nodiscard]] Vector2<int> &getPos() const override;

        void setAsset(const IAsset &asset) override;

        [[nodiscard]] const IAsset & getAsset() const override;
    };
}  // namespace ANAL

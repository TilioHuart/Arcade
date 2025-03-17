//
// EPITECH PROJECT, 2025
// ISprite
// File description:
// ISprite
//

#include "../DataStructures/Vector2.hpp"

namespace anal {
    class ISprite {
        virtual ~ISprite() = default;
        virtual Vector2<int> getPos() = 0;
        virtual void setPos(Vector2<int> pos) = 0;
    };
}  // namespace anal

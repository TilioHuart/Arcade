//
// EPITECH PROJECT, 2025
// IDisplayModule
// File description:
// IDisplayModule
//

#include "../Sprites/ISprite.hpp"
#include "../Sounds/ISounds.hpp"
#include <memory>
#include <vector>

namespace anal {
    class IDisplayModule {
       public:
        virtual void drawSprite(const ISprite &sprite) = 0;
        virtual void unloadSprite(std::unique_ptr<ISprite> sprite) = 0;
        virtual void setWindowTitle(const std::string &title) = 0;
        virtual void render(const ISprite &sprite) = 0;
        virtual void render(std::vector<ISprite &> sprites) = 0;
        virtual void clear() = 0;
        virtual void drawText(const std::string &str, Vector2<int> pos) = 0;
        virtual void playSound(ISound &) = 0;
    };
}  // namespace anal

//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// NcursesDisp.hpp
//

#include "ARenderer.hpp"
#include <ncurses.h>

namespace ANAL {
    class NcursesRenderer : public ARenderer {
       public:
        NcursesRenderer();
        ~NcursesRenderer() override;

        void drawEntity(const ANAL::IEntity &entity) override;
        void drawText(const std::string &str, ANAL::Vector2<int> pos) override;
        void setWindowTitle(const std::string &windowTitle) override;
        void render() override;
        std::vector<ANAL::Event> &getEvents() override;
        void clear() override;

       private:
        ANAL::Vector2<int> _upperLeftCornerPos;
        ANAL::Vector2<int> _windowSize;
        std::string _windowTitle;
        std::vector<ANAL::Event> _ncursesEvents;
        WINDOW *_window = nullptr;
    };
}  // namespace ANAL

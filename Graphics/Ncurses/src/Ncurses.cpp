//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// NcursesDisp.cpp
//

#include "./Ncurses.hpp"
#include "Events.hpp"
#include <map>
#include <ncurses.h>

/* cons */
/*     initscr(); */
/*     curs_set(0); */
/*     keypad(stdscr, TRUE); */
/*     noecho(); */
/*     nodelay(stdscr, TRUE); */

void ANAL::NcursesRenderer::drawEntity(const ANAL::IEntity &entity)
{
    /* if (entity.getPos().y > this->_windowSize.y || entity.getPos().x > this->_windowSize.x) */
    /*     throw EntityError("Entity can't be drawn outside of the window"); */
    mvprintw(this->_upperLeftCornerPos.y + entity.getPos().y,
        this->_upperLeftCornerPos.x + entity.getPos().x, "%c",
        entity.getAsset().getAlternateRender());
}

void ANAL::NcursesRenderer::drawText(
    const std::string &str, ANAL::Vector2<int> pos)
{
    /* if (pos.y > this->_windowSize.y || pos.x + str.length() > this->_windowSize.x) */
    /*     throw EntityError("Text can't be drawn outside of the window"); */
    mvprintw(this->_upperLeftCornerPos.y + pos.y,
        this->_upperLeftCornerPos.x + pos.x, "%s", str.c_str());
}

void ANAL::NcursesRenderer::setWindowTitle(const std::string &windowTitle)
{
    mvprintw(this->_upperLeftCornerPos.y - 3,
        this->_upperLeftCornerPos.x + (this->_windowSize.x / 2) -
            (int)(windowTitle.length() / 2),
        "%s", windowTitle.c_str());
}

void ANAL::NcursesRenderer::render()
{
    refresh();
}

std::vector<ANAL::Event> &ANAL::NcursesRenderer::getEvents()
{
}

void ANAL::NcursesRenderer::clear()
{
    clear();
}

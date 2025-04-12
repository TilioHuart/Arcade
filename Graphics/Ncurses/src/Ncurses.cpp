//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// NcursesDisp.cpp
//

#include "Ncurses.hpp"
#include "Events.hpp"
#include "IModule.hpp"
#include <map>
#include <ncurses.h>
#include <term.h>
#include <unistd.h>

ANAL::NcursesRenderer::NcursesRenderer()
    : _windowSize(32, 32), _upperLeftCornerPos(0, 0)
{
    this->_window = initscr();
    noecho();
    raw();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    this->_windowSize = ANAL::Vector2<int>(32, 32);
    this->_upperLeftCornerPos =
        ANAL::Vector2<int>((getmaxx(this->_window) - this->_windowSize.x) / 2,
            (getmaxy(this->_window) - this->_windowSize.y) / 2);
}

ANAL::NcursesRenderer::~NcursesRenderer()
{
    endwin();
}

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
    wrefresh(this->_window);
}

std::vector<ANAL::Event> &ANAL::NcursesRenderer::getEvents()
{
    std::vector<ANAL::Event> events;
    const std::map<ANAL::Keys, int> code{{Keys::KEY_A, 'a'},
        {Keys::KEY_B, 'b'}, {Keys::KEY_C, 'c'}, {Keys::KEY_D, 'd'},
        {Keys::KEY_E, 'e'}, {Keys::KEY_F, 'f'}, {Keys::KEY_G, 'g'},
        {Keys::KEY_H, 'h'}, {Keys::KEY_I, 'i'}, {Keys::KEY_J, 'j'},
        {Keys::KEY_K, 'k'}, {Keys::KEY_L, 'l'}, {Keys::KEY_M, 'm'},
        {Keys::KEY_N, 'n'}, {Keys::KEY_O, 'o'}, {Keys::KEY_P, 'p'},
        {Keys::KEY_Q, 'q'}, {Keys::KEY_R, 'r'}, {Keys::KEY_S, 's'},
        {Keys::KEY_T, 't'}, {Keys::KEY_U, 'u'}, {Keys::KEY_V, 'v'},
        {Keys::KEY_W, 'w'}, {Keys::KEY_X, 'x'}, {Keys::KEY_Y, 'y'},
        {Keys::KEY_Z, 'z'}, {Keys::KEY_0, '0'}, {Keys::KEY_1, '1'},
        {Keys::KEY_2, '2'}, {Keys::KEY_3, '3'}, {Keys::KEY_4, '4'},
        {Keys::KEY_5, '5'}, {Keys::KEY_6, '6'}, {Keys::KEY_7, '7'},
        {Keys::SPECIAL_KEY_SPACE, ' '}, {Keys::SPECIAL_KEY_BACKSPACE, 127}, 
        {Keys::SPECIAL_KEY_ENTER, '\n'},
        {Keys::KEY_8, '8'}, {Keys::KEY_9, '9'}, {Keys::ARROW_UP, KEY_UP},
        {Keys::ARROW_DOWN, KEY_DOWN}, {Keys::ARROW_LEFT, KEY_LEFT},
        {Keys::ARROW_RIGHT, KEY_RIGHT}};
    int ch;
    while ((ch = wgetch(this->_window)) != ERR) {
        mvprintw(12, 5, "bonbini : %i", ch);
        if (ch == KEY_MOUSE) {
            mvprintw(5, 5, "guzini");
            MEVENT mouseEvent;
            if (getmouse(&mouseEvent) == OK) {
                ANAL::Event mev;
                mev.type = EventType::MOUSE;
                if (mouseEvent.bstate & BUTTON1_PRESSED) {
                    mev.mouseEvent->key = MouseKeys::LEFT_CLICK;
                    mev.mouseEvent->state = State::PRESSED;
                }
                if (mouseEvent.bstate & BUTTON2_PRESSED) {
                    mev.mouseEvent->key = MouseKeys::RIGHT_CLICK;
                    mev.mouseEvent->state = State::PRESSED;
                }
                if (mouseEvent.bstate & BUTTON3_PRESSED) {
                    mev.mouseEvent->key = MouseKeys::MIDDLE_CLICK;
                    mev.mouseEvent->state = State::PRESSED;
                }
                if (mouseEvent.bstate & BUTTON1_RELEASED) {
                    mev.mouseEvent->key = MouseKeys::LEFT_CLICK;
                    mev.mouseEvent->state = State::RELEASED;
                }
                if (mouseEvent.bstate & BUTTON2_RELEASED) {
                    mev.mouseEvent->key = MouseKeys::RIGHT_CLICK;
                    mev.mouseEvent->state = State::RELEASED;
                }
                if (mouseEvent.bstate & BUTTON3_RELEASED) {
                    mev.mouseEvent->key = MouseKeys::MIDDLE_CLICK;
                    mev.mouseEvent->state = State::RELEASED;
                }
                mev.mouseEvent->coords = {mouseEvent.x, mouseEvent.y};
                this->_ncursesEvents.push_back(mev);
                break;
            }
        }
        for (auto it : code)
            if (ch == it.second) {
                ANAL::Event ev;
                ev.keyEvent->key = it.first;
                this->_ncursesEvents.push_back(ev);
                break;
            }
    }
    return this->_ncursesEvents;
}

void ANAL::NcursesRenderer::clear()
{
    wclear(this->_window);
    wrefresh(this->_window);
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::RENDERER;
}

std::unique_ptr<ANAL::IRenderer> uwu_entrypoint_renderer(void)
{
    return std::make_unique<ANAL::NcursesRenderer>();
}
}

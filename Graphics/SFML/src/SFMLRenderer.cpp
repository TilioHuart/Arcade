//
// EPITECH PROJECT, 2025
// Arcade
// File description:
// SFMLRenderer.cpp
//

#include "IModule.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <map>

#include "Events.hpp"
#include "SFMLRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <vector>

ANAL::SFMLRenderer::SFMLRenderer()
{
    this->_window =
        std::make_unique<sf::RenderWindow>(sf::VideoMode({900, 900}), "");

    this->_font = std::make_unique<sf::Font>();
    this->_font->loadFromFile(
        "./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf");
    if (this->_font == nullptr || this->_window == nullptr)
        throw Exception();
}

ANAL::SFMLRenderer::~SFMLRenderer()
{
    if (this->_window)
        this->_window->close();
}

void ANAL::SFMLRenderer::drawEntity(const ANAL::IEntity &entity)
{
    sf::Texture texture;
    sf::Sprite sprite;
    float cellSize = 900.0F / 32.0F;

    if (entity.getAsset().getTexturePath().empty())
        throw Exception();

    if (!texture.loadFromFile(entity.getAsset().getTexturePath()))
        throw Exception();

    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(entity.getPos().x) * cellSize,
        static_cast<float>(entity.getPos().y) * cellSize);

    this->_window->draw(sprite);
}

void ANAL::SFMLRenderer::drawText(
    const std::string &str, ANAL::Vector2<int> pos)
{
    sf::Text text;
    float cellSize = 900.0F / 32.0F;

    if (!this->_font)
        throw Exception();
    text.setFont(*this->_font);
    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setPosition(static_cast<float>(pos.x) * cellSize, static_cast<float>(pos.y) * cellSize);

    this->_window->draw(text);
}

void ANAL::SFMLRenderer::setWindowTitle(const std::string &windowTitle)
{
    this->_windowTitle = windowTitle;
    this->_window->setTitle(windowTitle);
}

void ANAL::SFMLRenderer::render()
{
    this->_window->display();
}

std::vector<ANAL::Event> &ANAL::SFMLRenderer::getEvents()
{
    sf::Event sfmlEvent;

    const std::map<ANAL::Keys, sf::Keyboard::Key> code{
        {Keys::KEY_A, sf::Keyboard::Key::A},
        {Keys::KEY_B, sf::Keyboard::Key::B},
        {Keys::KEY_C, sf::Keyboard::Key::C},
        {Keys::KEY_D, sf::Keyboard::Key::D},
        {Keys::KEY_E, sf::Keyboard::Key::E},
        {Keys::KEY_F, sf::Keyboard::Key::F},
        {Keys::KEY_G, sf::Keyboard::Key::G},
        {Keys::KEY_H, sf::Keyboard::Key::H},
        {Keys::KEY_I, sf::Keyboard::Key::I},
        {Keys::KEY_J, sf::Keyboard::Key::J},
        {Keys::KEY_K, sf::Keyboard::Key::K},
        {Keys::KEY_L, sf::Keyboard::Key::L},
        {Keys::KEY_M, sf::Keyboard::Key::M},
        {Keys::KEY_N, sf::Keyboard::Key::N},
        {Keys::KEY_O, sf::Keyboard::Key::O},
        {Keys::KEY_P, sf::Keyboard::Key::P},
        {Keys::KEY_Q, sf::Keyboard::Key::Q},
        {Keys::KEY_R, sf::Keyboard::Key::R},
        {Keys::KEY_S, sf::Keyboard::Key::S},
        {Keys::KEY_T, sf::Keyboard::Key::T},
        {Keys::KEY_U, sf::Keyboard::Key::U},
        {Keys::KEY_V, sf::Keyboard::Key::V},
        {Keys::KEY_W, sf::Keyboard::Key::W},
        {Keys::KEY_X, sf::Keyboard::Key::X},
        {Keys::KEY_Y, sf::Keyboard::Key::Y},
        {Keys::KEY_Z, sf::Keyboard::Key::Z},
        {Keys::KEY_0, sf::Keyboard::Key::Num0},
        {Keys::KEY_1, sf::Keyboard::Key::Num1},
        {Keys::KEY_2, sf::Keyboard::Key::Num2},
        {Keys::KEY_3, sf::Keyboard::Key::Num3},
        {Keys::KEY_4, sf::Keyboard::Key::Num4},
        {Keys::KEY_5, sf::Keyboard::Key::Num5},
        {Keys::KEY_6, sf::Keyboard::Key::Num6},
        {Keys::KEY_7, sf::Keyboard::Key::Num7},
        {Keys::KEY_8, sf::Keyboard::Key::Num8},
        {Keys::KEY_9, sf::Keyboard::Key::Num9}};

    while (this->_window->pollEvent(sfmlEvent)) {
        switch (sfmlEvent.type) {
            case sf::Event::KeyPressed: {
                for (auto it : code)
                    if (sfmlEvent.key.code == it.second) {
                        ANAL::Event ev;
                        ev.keyEvent->key = it.first;
                        this->_sfmlEvents.push_back(ev);
                        break;
                    }
                break;
            }
            case sf::Event::Closed: {
                ANAL::Event ev;
                ev.keyEvent->key = Keys::KEY_Q;
                this->_sfmlEvents.push_back(ev);
                break;
            }
            default:
                break;
        }
    }
    return this->_sfmlEvents;
}

void ANAL::SFMLRenderer::clear()
{
    this->_window->clear();
}

extern "C" {
ANAL::ModuleType uwu_get_module_type()
{
    return ANAL::ModuleType::RENDERER;
}

std::unique_ptr<ANAL::IRenderer> uwu_entrypoint_renderer(void)
{
    return std::make_unique<ANAL::SFMLRenderer>();
}
}

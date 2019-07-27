//
// Created by LazyMechanic on 30.06.2019.
//

#include "Input.h"

namespace te {
void Input::update()
{
    m_lastKeyState = m_curKeyState;
    m_lastButtonState = m_curButtonState;
    m_lastMousePosition = m_curMousePosition;
}

void Input::handleEvent(const sf::Event &inputEvent)
{
    switch(inputEvent.type) {
        case sf::Event::EventType::KeyPressed:
            m_curKeyState.set(inputEvent.key.code, true);
            break;
        case sf::Event::EventType::KeyReleased:
            m_curKeyState.set(inputEvent.key.code, false);
            break;
        case sf::Event::EventType::MouseButtonPressed:
            m_curButtonState.set(inputEvent.key.code, true);
            break;
        case sf::Event::EventType::MouseButtonReleased:
            m_curButtonState.set(inputEvent.key.code, false);
            break;
        case sf::Event::EventType::MouseMoved:
            m_curMousePosition = {inputEvent.mouseMove.x, inputEvent.mouseMove.y};
            break;
        default:
            // Unexpected event
            break;
    }
}

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
    if (key >= sf::Keyboard::Key::KeyCount ||
        key <= sf::Keyboard::Key::Unknown)
        return false;

    return m_curKeyState[key] && !m_lastKeyState[key];
}

bool Input::isKeyReleased(sf::Keyboard::Key key)
{
    if (key >= sf::Keyboard::Key::KeyCount ||
        key <= sf::Keyboard::Key::Unknown)
        return false;

    return !m_curKeyState[key] && m_lastKeyState[key];
}

bool Input::isKeyDown(sf::Keyboard::Key key)
{
    if (key >= sf::Keyboard::Key::KeyCount ||
        key <= sf::Keyboard::Key::Unknown)
        return false;

    return m_curKeyState[key];
}

bool Input::isButtonPressed(sf::Mouse::Button button)
{
    if (button >= sf::Mouse::Button::ButtonCount ||
        button < 0)
        return false;

    return m_curButtonState[button] && !m_lastButtonState[button];
}

bool Input::isButtonReleased(sf::Mouse::Button button)
{
    if (button >= sf::Mouse::Button::ButtonCount ||
        button < 0)
        return false;

    return !m_curButtonState[button] && m_lastButtonState[button];
}

bool Input::isButtonDown(sf::Mouse::Button button)
{
    if (button >= sf::Mouse::Button::ButtonCount ||
        button < 0)
        return false;

    return m_curButtonState[button];
}

sf::Vector2i Input::getMousePosition() const
{
    return m_curMousePosition;
}

sf::Vector2i Input::getDeltaMousePosition() const
{
    return m_lastMousePosition - m_curMousePosition;
}
}
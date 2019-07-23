//
// Created by LazyMechanic on 30.06.2019.
//

#pragma once

#include <bitset>
#include <SFML/Window.hpp>

namespace te {
class Input {
public:
    /**
     * \brief Update keys and buttons states
     */
    void update();

    /**
     * \brief Handle input event
     * \param inputEvent Input event
     */
    void handleEvent(const sf::Event& inputEvent);

    /**
     * \brief Check if key is pressed
     * \param key Key number
     * \return True if key is pressed once, false otherwise
     */
    bool isKeyPressed(sf::Keyboard::Key key);

    /**
     * \brief Check if key is released
     * \param key Key number
     * \return True if key is released, false otherwise
     */
    bool isKeyReleased(sf::Keyboard::Key key);

    /**
     * \brief Check if key is down
     * \param key Key number
     * \return True if key is pressed and down still, false otherwise
     */
    bool isKeyDown(sf::Keyboard::Key key);

    /**
     * \brief Check if button is pressed
     * \param button Button number
     * \return True if button is pressed, false otherwise
     */
    bool isButtonPressed(sf::Mouse::Button button);

    /**
     * \brief Check if button is released
     * \param button Button number
     * \return True if button is released, false otherwise
     */
    bool isButtonReleased(sf::Mouse::Button button);

    /**
     * \brief Check if button is down
     * \param button Button number
     * \return True if button is pressed and down still, false otherwise
     */
    bool isButtonDown(sf::Mouse::Button button);

    /**
     * \brief Get current mouse position
     * \return Mouse position
     */
    sf::Vector2i getMousePosition() const;

    /**
     * \brief Get delta between current and last mouse position
     * \return Delta mouse position
     */
    sf::Vector2i getDeltaMousePosition() const;

private:
    /**
     * \brief Current state of keys
     */
    std::bitset<sf::Keyboard::Key::KeyCount> m_curKeyState;

    /**
     * \brief Last state of keys
     */
    std::bitset<sf::Keyboard::Key::KeyCount> m_lastKeyState;

    /**
     * \brief Current state of mouse buttons
     */
    std::bitset<sf::Mouse::Button::ButtonCount> m_curButtonState;

    /**
     * \brief Last state of mouse buttons
     */
    std::bitset<sf::Mouse::Button::ButtonCount> m_lastButtonState;

    /**
     * \brief Current mouse position
     */
    sf::Vector2i m_curMousePosition;

    /**
     * \brief Last mouse position
     */
    sf::Vector2i m_lastMousePosition;
};
}

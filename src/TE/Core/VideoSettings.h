
//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

namespace te {
struct VideoSettings {
    enum WindowMode {
        Windowed = sf::Style::Default,
        Fullscreen = sf::Style::Fullscreen,
        BorderlessWindow = sf::Style::None
    };

    VideoSettings();

    /**
     * \brief Include size of window and bits per pixel
     */
    sf::VideoMode videoMode;

    /**
     * \brief Enable or disable vertical synchronization
     */
    bool verticalSync;

    /**
     * \brief Set window mode
     */
    WindowMode windowMode;

    /**
     * \brief Set frameRate limit
     */
    unsigned int frameRateLimit;
};
} // namespace te

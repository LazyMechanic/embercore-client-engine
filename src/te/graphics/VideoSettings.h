
//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

namespace te {
struct VideoSettings {
    enum WindowStyle {
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
     * \brief Set window style
     */
    WindowStyle windowStyle;

    /**
     * \brief Set frameRate limit
     */
    unsigned int frameRateLimit;
};

bool operator==(const VideoSettings& left, const VideoSettings& right);

bool operator!=(const VideoSettings& left, const VideoSettings& right);

} // namespace te


//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <SFML/Window.hpp>

namespace te {
class VideoSettings {
public:
    enum WindowMode {
        Windowed = sf::Style::Default,
        Fullscreen = sf::Style::Fullscreen,
        BorderlessWindow = sf::Style::None
    };

    /**
     * \brief Default VideoSettings constructor
     */
    VideoSettings();

    /**
     * \brief Specific VideoSettings constructor
     * \param videoMode Include size of window and bits per pixel
     * \param verticalSync Enable or disable vertical synchronization
     * \param windowMode Set window mode
     * \param framerateLimit Set framerate limit
     */
    VideoSettings(const sf::VideoMode &videoMode,
                  bool verticalSync,
                  WindowMode windowMode,
                  unsigned int framerateLimit);

    /**
     * \brief VideoSettings destructor
     */
    ~VideoSettings() = default;

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
     * \brief Set framerate limit
     */
    unsigned int framerateLimit;
};
}

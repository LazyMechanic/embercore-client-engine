
//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <SFML/Window.hpp>

namespace te {
class VideoSettings {
public:
    enum WindowMode {
        Windowed,
        Fullscreen,
        BorderlessWindow
    };

    /**
     * Default VideoSettings constructor
     */
    VideoSettings();

    /**
     * Specific VideoSettings constructor
     * @param videoMode Include size of window and bits per pixel
     * @param verticalSync Enable or disable vertical synchronization
     * @param windowMode Set window mode
     * @param framerateLimit Set framerate limit
     */
    VideoSettings(const sf::VideoMode &videoMode,
                  bool verticalSync,
                  WindowMode windowMode,
                  unsigned int framerateLimit);

    /**
     * VideoSettings destructor
     */
    ~VideoSettings() = default;

    /**
     * Include size of window and bits per pixel
     */
    sf::VideoMode videoMode;

    /**
     * Enable or disable vertical synchronization
     */
    bool verticalSync;

    /**
     * Set window mode
     */
    WindowMode windowMode;

    /**
     * Set framerate limit
     */
    unsigned int framerateLimit;
};
}

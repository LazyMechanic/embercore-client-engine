
//
// Created by LazyMechanic on 23.06.2019.
//

#include "VideoSettings.h"

namespace te {
VideoSettings::VideoSettings() :
        videoMode(sf::VideoMode()), verticalSync(false), windowMode(WindowMode::Fullscreen), framerateLimit(60)
{

}

VideoSettings::VideoSettings(const sf::VideoMode &videoMode,
                             bool verticalSync,
                             VideoSettings::WindowMode windowMode,
                             unsigned int framerateLimit) :
        videoMode(videoMode), verticalSync(verticalSync), windowMode(windowMode), framerateLimit(framerateLimit)
{

}
}
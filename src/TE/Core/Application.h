
//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <SFML/Window.hpp>
#include <TE/Core/AppTraits.h>
#include <TE/Core/VideoSettings.h>

namespace te {
class Application {
public:
    Application();

    Application(const AppTraits &appTraits, const VideoSettings& videoSettings);

    ~Application() = default;

    VideoSettings videoSettings;

    sf::RenderWindow window;
};
}


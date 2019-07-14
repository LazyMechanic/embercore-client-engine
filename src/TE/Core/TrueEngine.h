//
// Created by Mechanic on 22.06.2019.
//

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <TE/Core/VideoSettings.h>

namespace te {
class TrueEngine {
public:
    TrueEngine(const VideoSettings& startVideoSettings, const sf::String& title, const sf::Image& icon);

    ~TrueEngine() = default;

    int run();

    bool isRunning() const;

    void setVideoSettings(const VideoSettings& newSettings);

    const VideoSettings& getVideoSettings() const;

    void draw(const sf::Drawable& obj, const sf::RenderStates& states = sf::RenderStates::Default);

    sf::RenderWindow& getWindow();

private:
    void handleEvents();

    void update(float dt);

    void display();

    sf::RenderWindow m_window;

    VideoSettings m_videoSettings;

    bool m_isRunning = true;
};
}

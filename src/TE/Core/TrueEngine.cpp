//
// Created by Mechanic on 22.06.2019.
//
#include <thread>
#include <chrono>

#include <TE/Core/TrueEngine.h>

namespace te {
TrueEngine::TrueEngine(const VideoSettings &startVideoSettings, const sf::String &title, const sf::Image &icon) : 
    m_videoSettings(startVideoSettings),
    m_isRunning(true)
{
    m_window.create(startVideoSettings.videoMode, title, startVideoSettings.windowMode);
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

int TrueEngine::run()
{
    using namespace std::chrono_literals;
    using SecondPartial = std::chrono::duration<float, std::ratio<1>>;

    auto currentTime = std::chrono::steady_clock::now();
    auto lastTime = currentTime;
    while(isRunning()) {
        currentTime = std::chrono::steady_clock::now();

        float dt = std::chrono::duration_cast<SecondPartial>(currentTime - lastTime).count();
        lastTime = currentTime;

        handleEvents();
        update(dt);
        display();

        //std::this_thread::sleep_until(currentTime + 20ms);
    }
    return 0;
}

sf::RenderWindow& TrueEngine::getWindow()
{
    return m_window;
}

void TrueEngine::handleEvents()
{
    sf::Event e;
    while(m_window.pollEvent(e)) {
        switch (e.type) {
        case sf::Event::EventType::Closed:
            m_isRunning = false;
            break;
        }
    }
}

void TrueEngine::update(float dt)
{

}

void TrueEngine::display()
{
    m_window.clear();
    m_window.display();
}

bool TrueEngine::isRunning() const
{
    return m_isRunning;
}

void TrueEngine::setVideoSettings(const VideoSettings &newSettings)
{
    // TODO: set new video settings
}

const VideoSettings &TrueEngine::getVideoSettings() const
{
    return m_videoSettings;
}

void TrueEngine::draw(const sf::Drawable& obj, const sf::RenderStates& states)
{
    m_window.draw(obj, states);
}
}

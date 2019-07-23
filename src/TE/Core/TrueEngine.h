//
// Created by Mechanic on 22.06.2019.
//

#pragma once

#include <filesystem>

#include <SFML/Graphics.hpp>

#include "te/util/Singleton.h"
#include "te/core/VideoSettings.h"

namespace te {
class TrueEngine : public Singleton<TrueEngine> {
public:
    TrueEngine() = default;

    explicit TrueEngine(const std::filesystem::path& mainConfigFilePath);

    ~TrueEngine() = default;

    void run();

    bool isRunning() const;

    void draw(const sf::Drawable& obj, const sf::RenderStates& states = sf::RenderStates::Default);

    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow m_window;

    bool m_isRunning = true;

    void handleEvents();

    void update(float dt);

    void display();
};
} // namespace te

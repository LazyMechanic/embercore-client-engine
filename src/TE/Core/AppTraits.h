
//
// Created by LazyMechanic on 23.06.2019.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace te {
class AppTraits {
public:
    /**
     * Default AppTraits constructor
     */
    AppTraits();

    /**
     * Specific AppTraits constructor
     * @param title Window tittle
     * @param style Window style
     * @param contextSettings Settings of the OpenGL context attached to a window
     */
    explicit AppTraits(const sf::String &title,
                       sf::Uint32 style = sf::Style::Default,
                       const sf::ContextSettings &contextSettings = sf::ContextSettings());

    /**
     * AppTraits destructor
     */
    ~AppTraits() = default;

    /**
     * Window tittle
     */
    sf::String title;

    /**
     * Window style
     */
    sf::Uint32 style;

    /**
     * Settings of the OpenGL context attached to a window
     */
    sf::ContextSettings contextSettings;
};
}



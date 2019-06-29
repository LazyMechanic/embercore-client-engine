
//
// Created by LazyMechanic on 23.06.2019.
//

#include "AppTraits.h"

namespace te {
AppTraits::AppTraits(const sf::String &title,
                     sf::Uint32 style,
                     const sf::ContextSettings &contextSettings) :
        title(title),
        style(style),
        contextSettings(contextSettings)
{
}

AppTraits::AppTraits() :
        title("Window"),
        style(sf::Style::Default),
        contextSettings(sf::ContextSettings())
{

}
}

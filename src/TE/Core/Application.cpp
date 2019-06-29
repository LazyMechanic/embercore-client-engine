
//
// Created by LazyMechanic on 23.06.2019.
//

#include "Application.h"

namespace te {
Application::Application(const AppTraits &appTraits, const VideoSettings &videoSettings) :
        videoSettings(videoSettings),
        window()
{
    window.create(videoSettings.videoMode, appTraits.title, appTraits.style, appTraits.contextSettings);
}

Application::Application() = default;
}
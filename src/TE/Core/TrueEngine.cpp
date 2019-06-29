//
// Created by Mechanic on 22.06.2019.
//

#include "TrueEngine.h"

namespace te {
TrueEngine::TrueEngine(const AppTraits &appTraits, const VideoSettings &videoSettings) :
        m_application(appTraits, videoSettings)
{
}

TrueEngine::~TrueEngine() = default;

Application &TrueEngine::getApplication()
{
    return m_application;
}
}
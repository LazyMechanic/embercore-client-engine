//
// Created by Mechanic on 22.06.2019.
//

#pragma once

#include <string>
#include <istream>
#include <TE/Core/Application.h>

namespace te {
class TrueEngine {
public:
    /**
     * Specific TrueEngine constructor
     * @param appTraits Traits for start application
     * @param videoSettings Video settings by default
     */
    TrueEngine(const AppTraits& appTraits, const VideoSettings& videoSettings);

    ~TrueEngine();

    int run();

    Application& getApplication();
private:
    Application m_application;
};
}

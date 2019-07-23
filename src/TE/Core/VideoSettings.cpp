#include "VideoSettings.h"

namespace te {
VideoSettings::VideoSettings() :
    verticalSync(true),
    windowMode(WindowMode::Windowed),
    frameRateLimit(60)
{
}
}

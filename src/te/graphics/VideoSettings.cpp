#include "VideoSettings.h"

namespace te {
VideoSettings::VideoSettings() : verticalSync(true), windowStyle(WindowStyle::Windowed), frameRateLimit(60) {}

bool operator==(const VideoSettings& left, const VideoSettings& right)
{
    return left.verticalSync == right.verticalSync && left.videoMode == right.videoMode &&
           left.frameRateLimit == right.frameRateLimit && left.windowStyle == right.windowStyle;
}

bool operator!=(const VideoSettings& left, const VideoSettings& right)
{
    return !(left == right);
}
} // namespace te

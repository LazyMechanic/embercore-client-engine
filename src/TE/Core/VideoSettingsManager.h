#pragma once

#include <filesystem>

#include "te/core/VideoSettings.h"
#include "te/util/Singleton.h"

namespace te {
class VideoSettingsManager : public Singleton<VideoSettingsManager> {
public:
    VideoSettingsManager(const std::filesystem::path& configFilePath);

    ~VideoSettingsManager() = default;

    void set(const VideoSettings& settings);

    VideoSettings get() const;

private:
    VideoSettings m_videoSettings;

    const std::filesystem::path m_configFilePath;
};
} // namespace te
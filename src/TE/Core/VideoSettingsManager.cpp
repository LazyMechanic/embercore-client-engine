#include "VideoSettingsManager.h"

#include "te/filesystem/Filesystem.h"
#include "te/util/YamlParser.h"

namespace te {
VideoSettingsManager::VideoSettingsManager(const std::filesystem::path& configFilePath) :
    m_configFilePath(configFilePath)
{
    auto rawFileData = Filesystem::instance().read(configFilePath);
    const std::string yamlRawDocument(rawFileData.begin(), rawFileData.end());

    auto config = YamlParser::parse(yamlRawDocument);

    auto videoModeNode = config["VideoMode"];
    auto frameRateLimit = config["FrameRateLimit"];
    auto verticalSync = config["VerticalSync"];
    auto windowMode = config["WindowMode"];

    VideoSettings settings;

    // If config not have one of parameters
    if (!(!videoModeNode.IsDefined() || !frameRateLimit.IsDefined() || !verticalSync.IsDefined() ||
          !windowMode.IsDefined())) {
        settings.videoMode = sf::VideoMode(videoModeNode["Width"].as<int>(), videoModeNode["Height"].as<int>());
        settings.frameRateLimit = frameRateLimit.as<int>();
        settings.verticalSync = verticalSync.as<bool>();
        settings.windowMode = windowMode.as<VideoSettings::WindowMode>();
    }

    set(settings);
}

void VideoSettingsManager::set(const VideoSettings& settings)
{
    m_videoSettings = settings;

    // Save to file
    YAML::Node document;
    document["VideoMode"] = YAML::Node(YAML::NodeType::Map);
    document["VideoMode"]["Width"] = settings.videoMode.width;
    document["VideoMode"]["Height"] = settings.videoMode.height;
    document["FrameRateLimit"] = settings.frameRateLimit;
    document["VerticalSync"] = settings.verticalSync;
    document["WindowMode"] = settings.windowMode;

    const auto yamlString = YAML::Dump(document);
    Filesystem::instance().write(m_configFilePath, yamlString);
}

VideoSettings VideoSettingsManager::get() const
{
    return m_videoSettings;
}
} // namespace te

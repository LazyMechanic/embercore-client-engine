#include "Window.h"

#include <yaml-cpp/yaml.h>

#include "te/filesystem/Filesystem.h"

namespace te {
Window::Window() = default;

Window::Window(const std::string& title,
               const std::filesystem::path& iconPath,
               const std::filesystem::path& videoSettingsPath)
{
    // Read video settings file
    auto videoSettingsFileData = Filesystem::instance().read(videoSettingsPath);

    // If video settings file not found
    if (!videoSettingsFileData)
        throw std::runtime_error("Video settings file not found:\npath = { " + videoSettingsPath.string() + " }");

    const std::string yamlRawDocument(videoSettingsFileData->begin(), videoSettingsFileData->end());

    // Parse video settings
    auto config = YAML::Load(yamlRawDocument);

    auto videoModeNode = config["VideoMode"];
    auto frameRateLimit = config["FrameRateLimit"];
    auto verticalSync = config["VerticalSync"];
    auto windowStyle = config["WindowStyle"];

    VideoSettings settings;

    // If config not have one of parameters
    if (!(!videoModeNode.IsDefined() || !frameRateLimit.IsDefined() || !verticalSync.IsDefined() ||
          !windowStyle.IsDefined())) {
        settings.videoMode = sf::VideoMode(videoModeNode["Width"].as<int>(), videoModeNode["Height"].as<int>());
        settings.frameRateLimit = frameRateLimit.as<int>();
        settings.verticalSync = verticalSync.as<bool>();
        settings.windowStyle = static_cast<VideoSettings::WindowStyle>(windowStyle.as<int>());
    }

    // Save title
    m_title = title;

    // Save icon
    auto iconFile = Filesystem::instance().read(iconPath);

    // If icon file not found
    if (!iconFile)
        throw std::runtime_error("Icon file not found:\npath = { " + iconPath.string() + " }");

    m_icon.loadFromMemory(iconFile->data(), iconFile->size());

    applyVideoSettings(settings);
    setTitle(m_title);
    setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());
}

Window::~Window() = default;

void Window::applyVideoSettings(const VideoSettings& settings)
{
    // If no changes
    if (settings == m_videoSettings)
        return;

    create(settings.videoMode, getTitle(), settings.windowStyle);
    setFramerateLimit(settings.frameRateLimit);
    setVerticalSyncEnabled(settings.verticalSync);

    m_videoSettings = settings;
    saveToFile();
}

VideoSettings Window::getVideoSettings() const
{
    return m_videoSettings;
}

void Window::saveToFile() const
{
    // Save to file
    YAML::Node document;
    document["VideoMode"] = YAML::Node(YAML::NodeType::Map);
    document["VideoMode"]["Width"] = m_videoSettings.videoMode.width;
    document["VideoMode"]["Height"] = m_videoSettings.videoMode.height;
    document["FrameRateLimit"] = m_videoSettings.frameRateLimit;
    document["VerticalSync"] = m_videoSettings.verticalSync;
    document["WindowStyle"] = static_cast<int>(m_videoSettings.windowStyle);

    const auto yamlString = YAML::Dump(document);
    Filesystem::instance().write(m_videoSettingsPath, yamlString);
}

const std::string& Window::getTitle() const
{
    return m_title;
}

const sf::Image& Window::getIcon() const
{
    return m_icon;
}
} // namespace te

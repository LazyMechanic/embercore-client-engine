#pragma once

#include <filesystem>
#include <string>

#include <SFML/Graphics.hpp>

#include "te/graphics/VideoSettings.h"
#include "te/util/Singleton.h"

namespace te {
class Window : public Singleton<Window>, public sf::RenderWindow {
public:
    /**
     * \brief Window default constructor
     */
    Window();

    /**
     * \brief Window specific constructor
     * \param title Window title
     * \param iconPath Path to icon file
     * \param videoSettingsPath Path to video settings file
     */
    Window(const std::string& title,
           const std::filesystem::path& iconPath,
           const std::filesystem::path& videoSettingsPath);

    /**
     * \brief Window destructor
     */
    ~Window();

    /**
     * \brief Apply video settings and save to file
     * \param settings New video settings
     */
    void applyVideoSettings(const VideoSettings& settings);

    /**
     * \brief Get video settings
     * \return Current video settings
     */
    VideoSettings getVideoSettings() const;

    /**
     * \brief Get window title
     * \return Window title
     */
    const std::string& getTitle() const;

    /**
     * \brief Get window icon
     * \return Window icon
     */
    const sf::Image& getIcon() const;

private:
    /**
     * \brief Window icon
     */
    sf::Image m_icon;

    /**
     * \brief Window title
     */
    std::string m_title;

    /**
     * \brief Current video settings
     */
    VideoSettings m_videoSettings;

    /**
     * \brief Path to video settings config file
     */
    std::filesystem::path m_videoSettingsPath;

    /**
     * \brief Save video settings to file
     */
    void saveToFile() const;
};
} // namespace te
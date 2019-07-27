//
// Created by Mechanic on 22.06.2019.
//
#include "TrueEngine.h"

#include <chrono>
#include <filesystem>

#include <yaml-cpp/yaml.h>

#include "te/filesystem/Filesystem.h"
#include "te/graphics/Window.h"
#include "te/resource/ResourceManager.h"
#include "te/scene/SceneManager.h"
#include "te/script/ScriptManager.h"

namespace te {
TrueEngine::TrueEngine() : m_isRunning(true) {}

TrueEngine::TrueEngine(const std::filesystem::path& bootConfigFilePath) : m_isRunning(true)
{
    m_filesystem = std::make_unique<Filesystem>();
    m_resourceManager = std::make_unique<ResourceManager>();

    // Read boot config file
    auto bootConfigData = Filesystem::instance().read(bootConfigFilePath);

    // If boot config file not found
    if (!bootConfigData)
        throw std::runtime_error("Boot config file not found");

    const std::string bootConfig(bootConfigData->begin(), bootConfigData->end());

    // Parse raw string to yaml document
    auto yamlDocument = YAML::Load(bootConfig);

    // Window create
    const auto title = yamlDocument["Title"].as<std::string>();
    const auto iconPath = yamlDocument["IconPath"].as<std::string>();
    const auto videoSettingsPath = yamlDocument["VideoSettingsPath"].as<std::string>();
    m_window = std::make_unique<Window>(title, iconPath, videoSettingsPath);

    // Scene manager create
    const auto startScenePath = yamlDocument["StartScenePath"].as<std::string>();
    m_sceneManager = std::make_unique<SceneManager>(startScenePath);
}

TrueEngine::~TrueEngine() = default;

void TrueEngine::run()
{
    using namespace std::chrono_literals;
    using SecondPartial = std::chrono::duration<float, std::ratio<1>>;

    auto currentTime = std::chrono::steady_clock::now();
    auto lastTime = currentTime;
    while (isRunning()) {
        currentTime = std::chrono::steady_clock::now();

        float dt = std::chrono::duration_cast<SecondPartial>(currentTime - lastTime).count();
        lastTime = currentTime;

        handleEvents();
        update(dt);
        display();

        // std::this_thread::sleep_until(currentTime + 20ms);
    }
}

void TrueEngine::handleEvents()
{
    auto& window = Window::instance();

    sf::Event e{};
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::EventType::Closed:
                m_isRunning = false;
                break;
            default:
                // Unexpected event
                break;
        }
    }
}

void TrueEngine::update(float dt)
{
    SceneManager::instance().update(dt);
}

void TrueEngine::display()
{
    Window::instance().clear();
    Window::instance().display();
}

bool TrueEngine::isRunning() const
{
    return m_isRunning;
}
} // namespace te

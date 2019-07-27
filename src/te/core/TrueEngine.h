//
// Created by Mechanic on 22.06.2019.
//

#pragma once

#include <filesystem>
#include <memory>


#include "te/util/Singleton.h"

namespace te {
class Filesystem;
class ResourceManager;
class SceneManager;
class ScriptManager;
class Window;

class TrueEngine : public Singleton<TrueEngine> {
public:
    /**
     * \brief TrueEngine default constructor;
     */
    TrueEngine();

    /**
     * \brief TrueEngine specific constructor
     * \param bootConfigFilePath Path to boot config file
     */
    explicit TrueEngine(const std::filesystem::path& bootConfigFilePath);

    /**
     * \brief TrueEngine destructor
     */
    ~TrueEngine();

    /**
     * \brief Run engine
     */
    void run();

    /**
     * \brief Get application status
     * \return If app is running then return true, else return false
     */
    bool isRunning() const;

private:
    /**
     * \brief Window instance
     */
    std::unique_ptr<Window> m_window;

    /**
     * \brief Filesystem instance
     */
    std::unique_ptr<Filesystem> m_filesystem;

    /**
     * \brief ResourceManager instance
     */
    std::unique_ptr<ResourceManager> m_resourceManager;

    /**
     * \brief SceneManager instance
     */
    std::unique_ptr<SceneManager> m_sceneManager;

    /**
     * \brief ScriptManager instance
     */
    std::unique_ptr<ScriptManager> m_scriptManager;

    /**
     * \brief Application status
     */
    bool m_isRunning;

    /**
     * \brief Handle window events
     */
    void handleEvents();

    /**
     * \brief Update current scene
     * \param dt Delta time between current time and previous function calling
     */
    void update(float dt);

    /**
     * \brief Clear window and display content
     */
    void display();
};
} // namespace te

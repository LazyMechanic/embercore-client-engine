#pragma once

#include <filesystem>
#include <functional>
#include <memory>
#include <queue>
#include <stack>

#include "te/scene/Scene.h"
#include "te/util/Singleton.h"

namespace te {
class SceneManager : public Singleton<SceneManager> {
public:
    /**
     * \brief SceneManager default constructor
     */
    SceneManager();

    /**
     * \brief SceneManager specific constructor
     * \param startScenePath Path to start scene
     */
    explicit SceneManager(const std::filesystem::path& startScenePath);

    /**
     * \brief SceneManager destructor
     */
    ~SceneManager();

    /**
     * \brief Update current scene
     * \param dt Delta time between current time and previous call update function
     */
    void update(float dt);

    /**
     * \brief Draw objects in current scene
     */
    void draw();

    /**
     * \brief Push scene and set it as current
     */
    template <typename... Args>
    void push(Args&&... args);

    /**
     * \brief Pop current scene
     */
    void pop();

    /**
     * \brief Get count of scenes
     * \return Size of scene stack
     */
    std::size_t sceneCount() const;

    /**
     * \brief Check if scene stack is empty
     * \return True if scene stack is empty, false otherwise
     */
    bool isEmpty() const;

private:
    /**
     * \brief Stack of scenes
     */
    std::stack<std::unique_ptr<Scene>> m_scenes;

    /**
     * \brief Task to change scene
     */
    std::queue<std::function<void()>> m_tasks;
};

template <typename... Args>
void SceneManager::push(Args&&... args)
{
    m_tasks.emplace([&, this]() -> void { m_scenes.push(std::make_unique<Scene>(std::forward<Args>(args)...)); });
}
} // namespace te
#pragma once

#include <functional>
#include <memory>
#include <mutex>
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
     * \brief SceneManager destructor
     */
    ~SceneManager() = default;

    /**
     * \brief Update current scene
     * \param dt Delta time between current time and previous call update function
     */
    void update(float dt);

    /**
     * \brief Draw current scene
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

private:
    /**
     * \brief Stack of scenes
     */
    std::stack<std::unique_ptr<Scene>> m_scenes;

    std::queue<std::function<void()>> m_tasks;

    std::mutex m_tasksMutex;
};

template <typename... Args>
void SceneManager::push(Args&&... args)
{
    std::scoped_lock<std::mutex> lock(m_tasksMutex);
    m_tasks.emplace([&]() -> void { m_scenes.push(std::make_unique<Scene>(std::forward<Args>(args)...)); });
}
} // namespace te
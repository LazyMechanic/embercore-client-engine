#include "SceneManager.h"

#include "te/filesystem/Filesystem.h"

namespace te {
SceneManager::SceneManager() = default;

SceneManager::SceneManager(const std::filesystem::path& startScenePath)
{
    Filesystem::instance().read(startScenePath);
}

SceneManager::~SceneManager() = default;

void SceneManager::update(float dt)
{
    if (!m_scenes.empty())
        m_scenes.top()->update(dt);
}

void SceneManager::draw()
{
    if (!m_scenes.empty())
        m_scenes.top()->draw();
}

void SceneManager::pop()
{
    m_tasks.emplace([this]() -> void { m_scenes.pop(); });
}

std::size_t SceneManager::sceneCount() const
{
    return m_scenes.size();
}

bool SceneManager::isEmpty() const
{
    return m_scenes.empty();
}
} // namespace te

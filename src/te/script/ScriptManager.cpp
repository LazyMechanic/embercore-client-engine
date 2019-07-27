#include "ScriptManager.h"

#include <yaml-cpp/yaml.h>

#include "te/filesystem/Filesystem.h"

namespace te {
ScriptManager::ScriptManager() = default;

ScriptManager::ScriptManager(const std::filesystem::path& moduleDir, const std::filesystem::path& entryModulePath) :
    m_moduleDir(moduleDir)
{}

ScriptManager::~ScriptManager() = default;

sol::state& ScriptManager::state()
{
    return m_luaState;
}
} // namespace te

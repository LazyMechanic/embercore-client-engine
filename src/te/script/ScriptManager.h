#pragma once

#include <filesystem>

#include "te/util/Singleton.h"

#include <sol/sol.hpp>

namespace te {
class ScriptManager : public Singleton<ScriptManager> {
public:
    ScriptManager();

    ScriptManager(const std::filesystem::path& moduleDir, const std::filesystem::path& entryModulePath);

    ~ScriptManager();

    sol::state& state();

private:
    sol::state m_luaState;

    std::filesystem::path m_moduleDir;
};
} // namespace te
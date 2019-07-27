#pragma once

#include "te/util/Singleton.h"

namespace te {
class ScriptManager : public Singleton<ScriptManager> {
public:
    ScriptManager();

    ~ScriptManager();

private:
};
} // namespace te
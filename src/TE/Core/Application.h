#pragma once

#include <filesystem>

#include "te/core/TrueEngine.h"
#include "te/util/Singleton.h"

namespace te {
class Application : public Singleton<Application> {
public:
    Application(int argc, char** argv);

    int run() const;

private:
    std::unique_ptr<TrueEngine> m_engine;
};
} // namespace te
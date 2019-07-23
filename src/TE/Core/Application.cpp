#include "Application.h"

#include <cxxopts.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace te {
Application::Application(int argc, char** argv)
{
    cxxopts::Options options("TrueEngine"
                             "Simple 2D game engine");

    options.add_options()("c, config",
                          "Path to main config file (\"./some/path/to/config.json\" for example)",
                          cxxopts::value<std::filesystem::path>());

    auto parsedOptions = options.parse(argc, argv);

    std::filesystem::path configPath = std::filesystem::current_path();

    // If config file set manually
    if (parsedOptions.count("config") != 0)
        configPath = parsedOptions["config"].as<std::filesystem::path>();

    // If config file not found
    if (!std::filesystem::exists(configPath)) {
        std::cerr << "Main config file not found. By default path to it is \"./config.json\". You may set path by "
                     "argument \"-c | --config\""
                  << std::endl;
        throw std::runtime_error("Main config file not found");
    }


    // m_engine = std::make_unique<TrueEngine>();
}

int Application::run() const
{
    try {
        m_engine->run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}
} // namespace te

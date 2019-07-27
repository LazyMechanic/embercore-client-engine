#include "Application.h"

#include <filesystem>
#include <iostream>

#include <boost/program_options.hpp>

#include "te/core/TrueEngine.h"
#include "te/util/Log.h"

namespace po = boost::program_options;

namespace te {
Application::Application(int argc, char** argv) : m_appDescription("General options")
{
    // clang-format off
    m_appDescription.add_options()("config,c",
                                   po::value<std::filesystem::path>(),
                                   "Path to boot config file (\"./some/path/to/boot.yml\" for example)")
                                  ("help,h", 
                                   "Show help");
    // clang-format on

    po::store(po::parse_command_line(argc, argv, m_appDescription), m_appArgs);
    po::notify(m_appArgs);
}

Application::~Application() = default;

int Application::run()
{
    // Create log
    m_log = std::make_unique<Log>();

    //// Parse app arguments
    if (m_appArgs.count("help")) {
        std::cerr << m_appDescription << std::endl;
        return 2;
    }

    std::filesystem::path configPath = std::filesystem::current_path();
    // If config file set manually
    if (m_appArgs.count("config"))
        configPath = m_appArgs["config"].as<std::filesystem::path>();

    // If config file not found
    if (!std::filesystem::exists(configPath)) {
        std::cerr << m_appDescription << std::endl;
        std::cerr << "Boot config file not found" << std::endl;
        return 3;
    }

    try {
        m_engine = std::make_unique<TrueEngine>(configPath);
        m_engine->run();
    }
    catch (const std::exception& e) {
        Log::instance().critical("Handled exception: {}", e.what());
        return 1;
    }

    return 0;
}

const boost::program_options::variables_map& Application::getArgs() const
{
    return m_appArgs;
}

const boost::program_options::options_description& Application::getArgsDescription() const
{
    return m_appDescription;
}
} // namespace te

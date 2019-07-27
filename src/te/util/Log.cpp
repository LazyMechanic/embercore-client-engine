#include "Log.h"

#include <spdlog/async.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace te {
Log::Log()
{
    m_mainSinks = { std::make_shared<spdlog::sinks::rotating_file_sink_mt>("TrueEngine.log", 1024 * 1024, 5, false),
                    std::make_shared<spdlog::sinks::stderr_color_sink_mt>() };

    spdlog::init_thread_pool(8196, 1);
    m_mainLogger = std::make_shared<spdlog::async_logger>(
        "main_log", std::begin(m_mainSinks), std::end(m_mainSinks), spdlog::thread_pool());

    m_mainLogger->flush_on(spdlog::level::err);
    m_mainLogger->flush_on(spdlog::level::critical);

    info(">>> APPLICATION START <<<");
}

Log::~Log()
{
    info(">>> APPLICATION CLOSE <<<");
}

spdlog::logger& Log::logger()
{
    return *m_mainLogger;
}

void Log::log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const spdlog::string_view_t msg)
{
    m_mainLogger->log(loc, lvl, msg);
}

void Log::log(spdlog::level::level_enum lvl, spdlog::string_view_t msg)
{
    m_mainLogger->log(lvl, msg);
}
} // namespace te

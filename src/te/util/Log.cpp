#include "Log.h"

#pragma warning(push)
#pragma warning(disable : 26495)
#pragma warning(disable : 4099)
#pragma warning(disable : 4996)

#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace te {
Log::Log()
{
    // stderr
    auto stderrSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    stderrSink->set_level(spdlog::level::debug);
    stderrSink->set_pattern("[%H:%M:%S.%e] %^%-8l%$: %v");

    // Info level file
    auto infoFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("TrueEngine-info.log");
    infoFileSink->set_level(spdlog::level::info);
    infoFileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] %^%-8l%$: %v");

    // Err level file
    auto errFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("TrueEngine-err.log");
    errFileSink->set_level(spdlog::level::err);
    errFileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] %^%-8l%$: %v");

#ifdef TE_DEBUG_BUILD
    //// Create debug sinks
    // Debug level file
    auto debugFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("TrueEngine-debug.log");
    debugFileSink->set_level(spdlog::level::debug);
    debugFileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread: %t] %^%-8l%$: %v");

    // Trace level file
    auto traceFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("TrueEngine-trace.log");
    traceFileSink->set_level(spdlog::level::trace);
    traceFileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread: %t] %^%-8l%$: %v");
#endif // TE_DEBUG_BUILD

    m_mainSinks.push_back(infoFileSink);
    m_mainSinks.push_back(stderrSink);
    m_mainSinks.push_back(errFileSink);

#ifdef TE_DEBUG_BUILD
    //// Add debug sinks
    m_mainSinks.push_back(debugFileSink);
    m_mainSinks.push_back(traceFileSink);
#endif // TE_DEBUG_BUILD

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
} // namespace te

#pragma warning(pop)
#pragma once

#include <spdlog/spdlog.h>

#include "te/util/Singleton.h"

namespace te {
class Log : public Singleton<Log> {
public:
    Log();

    ~Log();

    spdlog::logger &logger();

    template <typename... Args>
    void trace(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void trace(const T &msg);

    template <typename... Args>
    void debug(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void debug(const T &msg);

    template <typename... Args>
    void info(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void info(const T &msg);

    template <typename... Args>
    void warn(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void warn(const T &msg);

    template <typename... Args>
    void error(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void error(const T &msg);

    template <typename... Args>
    void critical(spdlog::string_view_t fmt, Args &&... args);

    template <typename T>
    void critical(const T &msg);

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
#ifndef _WIN32
#error SPDLOG_WCHAR_TO_UTF8_SUPPORT only supported on windows
#else
    template <typename... Args>
    void trace(spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void debug(spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void info(spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void warn(spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void error(spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void critical(spdlog::wstring_view_t fmt, Args &&... args);
#endif // _WIN32
#endif // SPDLOG_WCHAR_TO_UTF8_SUPPORT

private:
    std::shared_ptr<spdlog::logger> m_mainLogger;

    std::vector<spdlog::sink_ptr> m_mainSinks;
};

#include "te/util/Log.inl"
} // namespace te
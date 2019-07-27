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

    template <typename... Args>
    void force_log(spdlog::source_loc loc, spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args);

    template <typename... Args>
    void log(spdlog::source_loc loc, spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args);

    template <typename... Args>
    void log(spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args);

    void log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const spdlog::string_view_t msg);

    void log(spdlog::level::level_enum lvl, spdlog::string_view_t msg);

    template <typename T>
    void log(spdlog::level::level_enum lvl, const T &msg);

    // T can be statically converted to string_view
    template <
        class T,
        typename std::enable_if<std::is_convertible<const T &, spdlog::string_view_t>::value, T>::type * = nullptr>
    void log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg);

    // T cannot be statically converted to string_view or wstring_view
    template <class T,
              typename std::enable_if<!std::is_convertible<const T &, spdlog::string_view_t>::value &&
                                          !spdlog::is_convertible_to_wstring_view<const T &>::value,
                                      T>::type * = nullptr>
    void log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg);

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
#ifndef _WIN32
#error SPDLOG_WCHAR_TO_UTF8_SUPPORT only supported on windows
#else
    template <typename... Args>
    void log(spdlog::source_loc source, spdlog::level::level_enum lvl, spdlog::wstring_view_t fmt, Args &&... args);

    template <typename... Args>
    void log(spdlog::level::level_enum lvl, spdlog::wstring_view_t fmt, Args &&... args);

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

    // T can be statically converted to wstring_view
    template <class T,
              typename std::enable_if<spdlog::is_convertible_to_wstring_view<const T &>::value, T>::type * = nullptr>
    void log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg);
#endif // _WIN32
#endif // SPDLOG_WCHAR_TO_UTF8_SUPPORT

private:
    std::shared_ptr<spdlog::logger> m_mainLogger;

    std::vector<spdlog::sink_ptr> m_mainSinks;
};

#include "te/util/Log.inl"
} // namespace te
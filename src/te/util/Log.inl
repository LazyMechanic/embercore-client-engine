template <typename... Args>
void Log::trace(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->trace(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::trace(const T &msg)
{
    m_mainLogger->trace(msg);
}

template <typename... Args>
void Log::debug(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->debug(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::debug(const T &msg)
{
    m_mainLogger->debug(msg);
}

template <typename... Args>
void Log::info(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->info(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::info(const T &msg)
{
    m_mainLogger->info(msg);
}

template <typename... Args>
void Log::warn(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->warn(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::warn(const T &msg)
{
    m_mainLogger->warn(msg);
}

template <typename... Args>
void Log::error(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->error(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::error(const T &msg)
{
    m_mainLogger->error(msg);
}

template <typename... Args>
void Log::critical(spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->critical(fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::critical(const T &msg)
{
    m_mainLogger->critical(msg);
}

template <typename... Args>
void Log::force_log(spdlog::source_loc loc, spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->force_log(loc, lvl, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::log(spdlog::source_loc loc, spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->log(loc, lvl, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::log(spdlog::level::level_enum lvl, spdlog::string_view_t fmt, Args &&... args)
{
    m_mainLogger->log(lvl, fmt, std::forward<Args>(args)...);
}

template <typename T>
void Log::log(spdlog::level::level_enum lvl, const T &msg)
{
    m_mainLogger->log(lvl, msg);
}

template <class T, typename std::enable_if<std::is_convertible<const T &, spdlog::string_view_t>::value, T>::type *>
void Log::log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg)
{
    m_mainLogger->log(loc, lvl, msg);
}

template <class T,
          typename std::enable_if<!std::is_convertible<const T &, fmt::basic_string_view<char>>::value &&
                                      !spdlog::is_convertible_to_wstring_view<const T &>::value,
                                  T>::type *>
void Log::log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg)
{
    m_mainLogger->log(loc, lvl, msg);
}

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
#ifndef _WIN32
#error SPDLOG_WCHAR_TO_UTF8_SUPPORT only supported on windows
#else
template <typename... Args>
void Log::log(spdlog::source_loc source, spdlog::level::level_enum lvl, spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->log(source, lvl, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::log(spdlog::level::level_enum lvl, spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->log(lvl, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::trace(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->trace(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::debug(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->debug(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::info(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->info(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::warn(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->warn(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::error(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->error(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void Log::critical(spdlog::wstring_view_t fmt, Args &&... args)
{
    m_mainLogger->critical(fmt, std::forward<Args>(args)...);
}

// T can be statically converted to wstring_view
template <class T,
          typename std::enable_if<spdlog::is_convertible_to_wstring_view<const T &>::value, T>::type * = nullptr>
void Log::log(spdlog::source_loc loc, spdlog::level::level_enum lvl, const T &msg)
{
    m_mainLogger->log(loc, lvl, msg);
}
#endif // _WIN32
#endif // SPDLOG_WCHAR_TO_UTF8_SUPPORT

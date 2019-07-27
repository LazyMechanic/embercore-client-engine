#pragma warning(push)
#pragma warning(disable : 26495)
#pragma warning(disable : 4099)
#pragma warning(disable : 4996) 

template < typename... Args>
void Log::trace(spdlog::string_view_t fmt, Args &&... args)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->trace(fmt, std::forward<Args>(args)...);
#endif
}

template <typename T>
void Log::trace(const T &msg)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->trace(msg);
#endif
}

template <typename... Args>
void Log::debug(spdlog::string_view_t fmt, Args &&... args)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->debug(fmt, std::forward<Args>(args)...);
#endif
}

template <typename T>
void Log::debug(const T &msg)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->debug(msg);
#endif
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

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
#ifndef _WIN32
#error SPDLOG_WCHAR_TO_UTF8_SUPPORT only supported on windows
#else
template <typename... Args>
void Log::trace(spdlog::wstring_view_t fmt, Args &&... args)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->trace(fmt, std::forward<Args>(args)...);
#endif
}

template <typename... Args>
void Log::debug(spdlog::wstring_view_t fmt, Args &&... args)
{
#ifdef TE_DEBUG_BUILD
    m_mainLogger->debug(fmt, std::forward<Args>(args)...);
#endif
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
#endif // _WIN32
#endif // SPDLOG_WCHAR_TO_UTF8_SUPPORT

#pragma warning(pop)
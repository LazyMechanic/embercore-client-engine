find_package(spdlog REQUIRED)

if (NOT ${spdlog_FOUND})
    message(FATAL_ERROR "spdlog couldn't be located")
endif()

set(SPDLOG_LIBRARIES_IN
        spdlog::spdlog)
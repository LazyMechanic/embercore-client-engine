find_package(EnTT CONFIG REQUIRED)

if (NOT ${EnTT_FOUND})
    message(FATAL_ERROR "EnTT couldn't be located")
endif()

set(ENTT_LIBRARIES
        EnTT)
find_package(sol2 CONFIG REQUIRED)

if (NOT ${sol2_FOUND})
    message(FATAL_ERROR "Sol2 couldn't be located")
endif()

set(SOL2_LIBRARIES
        sol2::sol2)
find_package(cxxopts CONFIG REQUIRED)

if (NOT ${cxxopts_FOUND})
    message(FATAL_ERROR "cxxopts couldn't be located")
endif()

set(CXXOPTS_LIBRARIES_IN
        cxxopts::cxxopts)
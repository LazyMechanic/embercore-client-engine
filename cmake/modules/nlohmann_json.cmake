find_package(nlohmann_json CONFIG REQUIRED)

if (NOT ${nlohmann_json_FOUND})
    message(FATAL_ERROR "nlohmann_json couldn't be located")
endif()

set(NLOHMANN_JSON_LIBRARIES_IN
        nlohmann_json::nlohmann_json)
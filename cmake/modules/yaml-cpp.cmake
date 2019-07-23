find_package(yaml-cpp CONFIG REQUIRED)

if (NOT ${yaml-cpp_FOUND})
    message(FATAL_ERROR "yaml-cpp couldn't be located")
endif()

set(YAML_CPP_LIBRARIES_IN
        yaml-cpp)
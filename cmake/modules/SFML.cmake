find_package(SFML 2.5 COMPONENTS system window network graphics audio REQUIRED)

if (NOT ${SFML_FOUND})
    message(FATAL_ERROR "SFML couldn't be located")
endif()

set(SFML_LIBRARIES_IN
        sfml-system
        sfml-graphics
        sfml-network
        sfml-window
        sfml-audio)
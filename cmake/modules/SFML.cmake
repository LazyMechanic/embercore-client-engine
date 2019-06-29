# Set static linking
set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)

set(SFML_DIR ${CMAKE_MODULE_PATH})
set(SFML_ROOT ${PROJECT_EXTLIBS_DIR}/libs-SFML/)

set(SFML_LIBS_DEPENDENCIES_DIR ${PROJECT_EXTLIBS_DIR}/libs-SFML/extlibs/libs-mingw/${SYSTEM_BIT_POSTFIX})
set(SFML_INCLUDE_DEPENDENCIES_DIR ${PROJECT_EXTLIBS_DIR}/libs-SFML/extlibs/headers)

set(ENV{OPENALDIR} ${SFML_LIBS_DEPENDENCIES_DIR})
set(VORBIS_LIBRARY ${SFML_LIBS_DEPENDENCIES_DIR})
set(VORBISFILE_LIBRARY ${SFML_LIBS_DEPENDENCIES_DIR})
set(VORBISENC_LIBRARY ${SFML_LIBS_DEPENDENCIES_DIR})

set(OPENAL_INCLUDE_DIR ${SFML_INCLUDE_DEPENDENCIES_DIR}/AL)

find_package(SFML 2.5 COMPONENTS system window network graphics audio QUIET)

# If not found pre-compiled SFML then build it
if (NOT ${SFML_FOUND})
    add_subdirectory(${PROJECT_EXTLIBS_DIR}/libs-SFML)
endif()

set(SFML_LIBRARIES
        sfml-system
        sfml-window
        sfml-network
        sfml-graphics
        sfml-audio)

set(SFML_DEPENDENCIES
        ${SFML_LIBS_DEPENDENCIES_DIR}/libfreetype.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libopenal32.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libFLAC.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbisenc.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbisfile.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbis.a
        ${SFML_LIBS_DEPENDENCIES_DIR}/libogg.a)

set(SFML_INCLUDE_DIR
        ${PROJECT_EXTLIBS_DIR}/libs-SFML/include)
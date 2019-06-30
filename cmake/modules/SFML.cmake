## Set static linking
set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)

## Set SFML paths
# Path for find SFMLConfig.cmake
set(SFML_DIR ${CMAKE_MODULE_PATH})
# SFML root path
set(SFML_ROOT ${PROJECT_EXTLIBS_DIR}/libs-SFML/)

# Path to dependecies libs folder
set(SFML_LIBS_DEPENDENCIES_DIR ${PROJECT_EXTLIBS_DIR}/libs-SFML/extlibs/libs-mingw/${SYSTEM_BIT_POSTFIX})
# Path to dependecies includes folder
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

## Set path to SFML compiled libs
foreach(SFML_CUR_TARGET ${SFML_LIBRARIES})
    set_target_properties(${SFML_CUR_TARGET} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${SFML_ROOT}/lib/${PROJECT_BUILD_TYPE}
            SHARED_OUTPUT_DIRECTORY ${SFML_ROOT}/lib/${PROJECT_BUILD_TYPE})
endforeach()

# If Vorbies libs not found in default paths
if (NOT DEFINED ${VORBIS_FOUND})
    set(VORBIS_LIBRARIES
            ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbisenc.a
            ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbisfile.a
            ${SFML_LIBS_DEPENDENCIES_DIR}/libvorbis.a
            ${SFML_LIBS_DEPENDENCIES_DIR}/libogg.a)
endif()

set(SFML_DEPENDENCIES
        ${FREETYPE_LIBRARY}
        ${OPENAL_LIBRARY}
        ${FLAC_LIBRARY}
        ${VORBIS_LIBRARIES})

set(SFML_INCLUDE_DIR
        ${PROJECT_EXTLIBS_DIR}/libs-SFML/include)
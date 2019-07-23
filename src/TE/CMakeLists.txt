include(TrueEngineBuildHelper)

############# CORE #############
te_add_prefix_to_sources(PREFIX "core"
    OUT TE_CORE_SRCS
    FILES 
        "main.cpp"
        "Application.cpp"
        "Application.h"
        "TrueEngine.cpp"
        "TrueEngine.h"
        "VideoSettings.cpp"
        "VideoSettings.h")
        
############# FILESYSTEM #############
te_add_prefix_to_sources(PREFIX "filesystem"
    OUT TE_FILESYSTEM_SRCS
    FILES 
        "FileData.h"
        "Filesystem.cpp"
        "Filesystem.h"
        "Filesystem.inl"
        "IFilesystemCache.h"
        "IFilesystemReader.h"
        "IFilesystemWriter.h"
        "FilesystemRawReader.h"
        "FilesystemRawReader.cpp"
        "FilesystemStaticCache.h"
        "FilesystemStaticCache.cpp")
        
############# INPUT #############
te_add_prefix_to_sources(PREFIX "input"
    OUT TE_INPUT_SRCS
    FILES 
        "Input.cpp"
        "Input.h")
        
############# RESOURCE #############
te_add_prefix_to_sources(PREFIX "resource"
    OUT TE_RESOURCE_SRCS
    FILES 
        "BaseBuilder.h"
        "ResourceManager.cpp"
        "ResourceManager.h"
        "TextureBuilder.cpp"
        "TextureBuilder.h")
        
############# SCENE #############
te_add_prefix_to_sources(PREFIX "scene"
    OUT TE_SCENE_SRCS
    FILES 
        "Scene.cpp"
        "Scene.h"
        "SceneManager.cpp"
        "SceneManager.h")
        
############# UTIL #############
te_add_prefix_to_sources(PREFIX "util"
    OUT TE_UTIL_SRCS
    FILES 
        "Singleton.h"
        "Singleton.inl"
        "YamlParser.cpp"
        "YamlParser.h"
        "YamlParser.inl")
        
set(TE_SRCS
    "${TE_CORE_SRCS}"
    "${TE_FILESYSTEM_SRCS}"
    "${TE_INPUT_SRCS}"
    "${TE_RESOURCE_SRCS}"
    "${TE_SCENE_SRCS}"
    "${TE_UTIL_SRCS}")

add_executable(TrueEngine "${TE_SRCS}")

set_target_properties(TrueEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_DIR}")

# Link libraries
target_link_libraries(TrueEngine
    "${TRUEENGINE_DEPENDENCIES_LIBS}")

# Include directory
target_include_directories(TrueEngine
    PRIVATE "${PROJECT_SRC_DIR}")

include(TrueEngineDllCopy)

install(DIRECTORY ${PROJECT_OUTPUT_DIR}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/)
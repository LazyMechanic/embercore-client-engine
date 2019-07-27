include(TrueEngineBuildHelper)

############# CORE #############
te_add_prefix_to_sources(PREFIX "core"
    OUT TE_CORE_SRCS
    FILES 
        "main.cpp"
        "Application.h"
        "Application.cpp"
        "TrueEngine.h"
        "TrueEngine.cpp")
        
############# FILESYSTEM #############
te_add_prefix_to_sources(PREFIX "filesystem"
    OUT TE_FILESYSTEM_SRCS
    FILES 
        "FileData.h"
        "Filesystem.h"
        "Filesystem.cpp"
        "FilesystemReaderImpl.h"
        "FilesystemReaderImpl.cpp"
        "FilesystemWriterImpl.h"
        "FilesystemWriterImpl.cpp")
        
############# GRAPHICS #############
te_add_prefix_to_sources(PREFIX "graphics"
    OUT TE_GRAPHICS_SRCS
    FILES 
        "Window.h"
        "Window.cpp"
        "VideoSettings.h"
        "VideoSettings.cpp")
        
############# INPUT #############
te_add_prefix_to_sources(PREFIX "input"
    OUT TE_INPUT_SRCS
    FILES 
        "Input.cpp"
        "Input.h")
        
############# NETWORK #############
te_add_prefix_to_sources(PREFIX "network"
    OUT TE_NETWORK_SRCS
    FILES 
        "Network.h"
        "Network.cpp")
        
############# RESOURCE #############
te_add_prefix_to_sources(PREFIX "resource"
    OUT TE_RESOURCE_SRCS
    FILES 
        "BaseBuilder.h"
        "ResourceManager.h"
        "ResourceManager.cpp"
        "TextureBuilder.h"
        "TextureBuilder.cpp")
        
############# SCENE #############
te_add_prefix_to_sources(PREFIX "scene"
    OUT TE_SCENE_SRCS
    FILES 
        "Scene.h"
        "Scene.cpp"
        "SceneManager.h"
        "SceneManager.cpp")
        
############# SCRIPT #############
te_add_prefix_to_sources(PREFIX "script"
    OUT TE_SCRIPT_SRCS
    FILES 
        "ScriptManager.h"
        "ScriptManager.cpp")
        
############# UTIL #############
te_add_prefix_to_sources(PREFIX "util"
    OUT TE_UTIL_SRCS
    FILES 
        "Singleton.h"
        "Singleton.inl"
        "Utility.h"
        "Utility.cpp"
        "Utility.inl"
        "Log.h"
        "Log.cpp"
        "Log.inl")
        
set(TE_SRCS
    "${TE_CORE_SRCS}"
    "${TE_FILESYSTEM_SRCS}"
    "${TE_INPUT_SRCS}"
    "${TE_GRAPHICS_SRCS}"
    "${TE_NETWORK_SRCS}"
    "${TE_RESOURCE_SRCS}"
    "${TE_SCENE_SRCS}"
    "${TE_SCRIPT_SRCS}"
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
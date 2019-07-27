cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(TrueEngine)

# Cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)
#set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "lib")
set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES} ".a" ".lib")

# Make x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SYSTEM_BIT_SUFFIX x64)
    # Make x86
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SYSTEM_BIT_SUFFIX x86)
endif()

# OS
if (WIN32)
    add_definitions(-DSYSTEM_WINDOWS)
endif (WIN32)
if (UNIX)
    add_definitions(-DSYSTEM_UNIX)
endif (UNIX)

string(TOLOWER "${CMAKE_BUILD_TYPE}" PROJECT_BUILD_TYPE)
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}")
set(PROJECT_SRC_DIR "${PROJECT_DIR}/src")
set(PROJECT_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin")

include(TrueEngineDependencies)

add_subdirectory(src/TE)
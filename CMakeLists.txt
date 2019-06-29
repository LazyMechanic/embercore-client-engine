cmake_minimum_required(VERSION 3.14)
project(TrueEngine)

set(CMAKE_CXX_STANDARD 17)

# Make x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SYSTEM_BIT_POSTFIX x64)
    # Make x86
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(SYSTEM_BIT_POSTFIX x86)
endif()

# OS
if (WIN32)
    add_definitions(-DSYSTEM_WINDOWS)
endif (WIN32)
if (UNIX)
    add_definitions(-DSYSTEM_UNIX)
endif (UNIX)

# Cmake module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_SRC_DIR ${PROJECT_DIR}/src)
set(PROJECT_OUTPUT_DIR ${PROJECT_DIR}/bin)
set(PROJECT_EXTLIBS_DIR ${PROJECT_DIR}/extlibs)

# Find or build SFML
include(SFML)
# Find or build Lua
include(Lua)
# Find Sol2
include(Sol2)

add_subdirectory(src/TE)
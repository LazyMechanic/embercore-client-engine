
set(LUA_DIR "${PROJECT_EXTLIBS_DIR}/libs-lua/lib")

find_package(Lua QUIET)

# If not found pre-compiled lua then build it
if (NOT ${LUA_FOUND})
    add_subdirectory(${PROJECT_EXTLIBS_DIR}/libs-lua)

    set(LUA_LIBRARIES lualib)
    set(LUA_INCLUDE_DIR ${PROJECT_EXTLIBS_DIR}/libs-lua/include)
endif()
if (DEFINED LUA_DIR)
    set(ENV{LUA_DIR} ${LUA_DIR})
endif()

find_package(Lua "5.3" REQUIRED)

# If not found pre-compiled lua
if (NOT ${LUA_FOUND})
    message(FATAL_ERROR "Lua couldn't be located")
endif()

set(_LUA_DLLS "lua53.dll")

add_library(LuaTarget SHARED IMPORTED)
set_target_properties(LuaTarget PROPERTIES
    IMPORTED_LOCATION ${_LUA_DLLS}
    IMPORTED_IMPLIB ${LUA_LIBRARIES}
    INTERFACE_INCLUDE_DIRECTORIES ${LUA_INCLUDE_DIR})

set(LUA_LIBRARIES_IN LuaTarget)
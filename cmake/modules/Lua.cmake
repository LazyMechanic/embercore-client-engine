if (DEFINED LUA_DIR)
    set(ENV{LUA_DIR} ${LUA_DIR})
endif()

find_package(Lua "5.3" REQUIRED)

# If not found pre-compiled lua
if (NOT ${LUA_FOUND})
    message(FATAL_ERROR "Lua couldn't be located")
endif()

set(LUA_ROOT ${PROJECT_EXTLIBS_DIR}/libs-lua)
set(ENV{LUA_DIR} ${LUA_ROOT}/lib/${PROJECT_BUILD_TYPE})

find_package(Lua QUIET)

# If not found pre-compiled lua then build it
if (NOT ${LUA_FOUND})
    add_subdirectory(${PROJECT_EXTLIBS_DIR}/libs-lua)

    set(LUA_LIBRARIES liblua)
    set(LUA_INCLUDE_DIR ${PROJECT_EXTLIBS_DIR}/libs-lua/include)

    set_target_properties(liblua PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${LUA_ROOT}/lib/${PROJECT_BUILD_TYPE}
            SHARED_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR})
endif()
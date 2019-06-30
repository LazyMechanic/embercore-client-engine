if(WIN32)
    add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()

project(liblua C)

file(GLOB LUA_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library (liblua STATIC
        ${LUA_SRCS})

set_target_properties(liblua PROPERTIES
        OUTPUT_NAME "lua")
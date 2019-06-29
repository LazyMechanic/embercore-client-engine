if(WIN32)
    add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()

file(GLOB LUA_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library (lualib STATIC
        ${LUA_SRCS})

set_target_properties(lualib PROPERTIES
        OUTPUT_NAME "lua")
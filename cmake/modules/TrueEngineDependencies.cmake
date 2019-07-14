include(EnTT)
include(Lua)
include(Protobuf)
include(Protocol)
include(SFML)
include(Sol2)

set(TRUEENGINE_DEPENDENCIES_LIBS
    ${LUA_LIBRARIES}
    ${SOL2_LIBRARIES}
    ${ENTT_LIBRARIES}
    ${SFML_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    ${PROTOCOL_LIBRARIES})

set(TRUEENGINE_DEPENDENCIES_INCLUDES
    ${LUA_INCLUDE_DIR})
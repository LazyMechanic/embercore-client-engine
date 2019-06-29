set(TRUEENGINE_SRC_DIR ${PROJECT_DIR}/src/TE)

# ================= CORE ================= #
set(TRUEENGINE_CORE_SRCS
    Core/main.cpp
    Core/TrueEngine.cpp Core/TrueEngine.h
    Core/AppTraits.cpp Core/AppTraits.h
    Core/VideoSettings.cpp Core/VideoSettings.h
    Core/Application.cpp Core/Application.h)
# ----------------- end CORE ----------------- #

# Static linking
add_definitions(-DSFML_STATIC)

set(TRUEENGINE_ALL_SRCS
        ${TRUEENGINE_CORE_SRCS})

# Create executable target
add_executable(TrueEngine
        ${TRUEENGINE_ALL_SRCS})

add_dependencies(TrueEngine
        ${SFML_LIBRARIES}
        ${LUA_LIBRARIES})

set_target_properties(TrueEngine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR})

# Link libraries
target_link_libraries(TrueEngine
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        ${LUA_LIBRARIES})

# Include directory
target_include_directories(TrueEngine
        PRIVATE ${PROJECT_SRC_DIR}
        PUBLIC ${SFML_INCLUDE_DIR}
        PRIVATE ${LUA_INCLUDE_DIR})
set(TRUEENGINE_SRC_DIR ${PROJECT_DIR}/src/TE)

# ================= CORE ================= #
set(TRUEENGINE_CORE_SRCS
    Core/main.cpp
    Core/TrueEngine.cpp Core/TrueEngine.h
    Core/VideoSettings.cpp Core/VideoSettings.h
    Core/Input.cpp Core/Input.h
    Core/Scene.cpp Core/Scene.h
    Core/SceneManager.cpp Core/SceneManager.h)
# ----------------- end CORE ----------------- #

# Create executable target
add_executable(TrueEngine
    ${TRUEENGINE_CORE_SRCS}
    "D:/Projects/embercore-protocol/cpp/src/protocol/auth.pb.cc"
    "D:/Projects/embercore-protocol/cpp/src/protocol/base.pb.cc")

set_target_properties(TrueEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR})

# Link libraries
target_link_libraries(TrueEngine
    ${TRUEENGINE_DEPENDENCIES_LIBS})

# Include directory
target_include_directories(TrueEngine
    PRIVATE ${PROJECT_SRC_DIR}
    PUBLIC ${TRUEENGINE_DEPENDENCIES_INCLUDES})

# Set SFML dll suffix for copy
if(${PROJECT_BUILD_TYPE} STREQUAL "debug")
    set(SFML_DLL_SUFFIX "-d-2")
endif()
if(${PROJECT_BUILD_TYPE} STREQUAL "release")
    set(SFML_DLL_SUFFIX "-2")
endif()

include(TrueEngineBuildHelper)
te_copy_dependencies_bins(TARGET TrueEngine
    DEPENDENCY_PATTERNS
        "${SFML_DIR}/../../../bin/*sfml-window${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-system${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-network${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-graphics${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-audio${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/openal32.dll"
        "${LUA_DIR}/lua53.dll"
    DESTINATION ${PROJECT_OUTPUT_DIR})

install(DIRECTORY ${PROJECT_OUTPUT_DIR}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/)
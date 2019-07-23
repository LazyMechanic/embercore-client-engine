set(SFML_DLLS "")
if(NOT SFML_STATIC_LIBRARIES)
    # Set SFML dll suffix for copy
    set(SFML_DLL_SUFFIX "-2")
    if(${PROJECT_BUILD_TYPE} STREQUAL "debug")
        set(SFML_DLL_SUFFIX "-d-2")
    endif()

    set(SFML_DLLS
        "${SFML_DIR}/../../../bin/*sfml-window${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-system${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-network${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-graphics${SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-audio${SFML_DLL_SUFFIX}.dll")

    unset(SFML_DLL_SUFFIX)
endif()

set(COMPILER_DLLS "")
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(COMPILER_DLLS "${CMAKE_SOURCE_DIR}/third_party/mingw/*.dll")
endif()

include(TrueEngineBuildHelper)
te_copy_dependencies_bins(TARGET TrueEngine
    DEPENDENCY_PATTERNS
        "${COMPILER_DLLS}"
        "${SFML_DLLS}"
        "${SFML_DIR}/../../../bin/openal32.dll"
        "${LUA_DIR}/lua53.dll"
    DESTINATION ${PROJECT_OUTPUT_DIR})

unset(SFML_DLLS)
unset(COMPILER_DLLS)
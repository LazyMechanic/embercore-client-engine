## Set sfml dlls
set(_SFML_DLLS "${SFML_DIR}/../../../bin/openal32.dll")
if(NOT SFML_STATIC_LIBRARIES)
    # Set SFML dll debug suffix for copy
    set(_SFML_DLL_SUFFIX "-2")
    if(${PROJECT_BUILD_TYPE} STREQUAL "debug")
        set(_SFML_DLL_SUFFIX "-d-2")
    endif()

    set(_SFML_DLLS
        "${_SFML_DLLS}"
        "${SFML_DIR}/../../../bin/*sfml-window${_SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-system${_SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-network${_SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-graphics${_SFML_DLL_SUFFIX}.dll"
        "${SFML_DIR}/../../../bin/*sfml-audio${_SFML_DLL_SUFFIX}.dll")

    unset(_SFML_DLL_SUFFIX)
endif()

## Set lua dlls
set(_LUA_DLLS "${LUA_DIR}/lua53.dll")

## Set boost dlls
set(_BOOST_DLLS "")
if(Boost_SHARED_LIBS)
    # Set boost dll debug suffix for copy
    set(_BOOST_DLL_SUFFIX "-${SYSTEM_BIT_SUFFIX}-1_70")
    if(${PROJECT_BUILD_TYPE} STREQUAL "debug")
        set(_BOOST_DLL_SUFFIX "-*d-${SYSTEM_BIT_SUFFIX}-1_70")
    endif()

    set(_BOOST_DLLS 
        "${Boost_DIR}/../../*boost_system-*-mt${_BOOST_DLL_SUFFIX}.dll"
        "${Boost_DIR}/../../*boost_program_options-*-mt${_BOOST_DLL_SUFFIX}.dll")
    
    unset(_BOOST_DLL_SUFFIX)
endif()

## Set compiler dlls
set(_COMPILER_DLLS "")
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND NOT MSVC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(_COMPILER_DLLS "${CMAKE_SOURCE_DIR}/third_party/mingw/*.dll")
endif()

## Create targets to copy dlls
include(TrueEngineBuildHelper)
te_copy_dependencies_bins(TARGET TrueEngine
    DEPENDENCY_PATTERNS
        "${_COMPILER_DLLS}"
        "${_SFML_DLLS}"
        "${_LUA_DLLS}"
        "${_BOOST_DLLS}"
    DESTINATION ${PROJECT_OUTPUT_DIR})

unset(_SFML_DLLS)
unset(_LUA_DLLS)
unset(_BOOST_DLLS)
unset(_COMPILER_DLLS)
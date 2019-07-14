function(TE_COPY_DEPENDENCIES_BINS)
    set(options OPTIONAL FAST)
    set(oneValueArgs TARGET DESTINATION)
    set(multiValueArgs DEPENDENCY_PATTERNS)
    cmake_parse_arguments(TE "${options}" "${oneValueArgs}" "${multiValueArgs}" "${ARGN}")

    file(GLOB DEPENDENCY_FILES ${TE_DEPENDENCY_PATTERNS})

    set(COPY_TARGETS "")

    foreach(DEPENDENCY_FILE ${DEPENDENCY_FILES})
        get_filename_component(CURRENT_TARGET ${DEPENDENCY_FILE} NAME_WE)
        add_custom_target(${CURRENT_TARGET}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DEPENDENCY_FILE}" "${TE_DESTINATION}")

        set(COPY_TARGETS ${COPY_TARGETS} ${CURRENT_TARGET})
    endforeach()

    add_dependencies(${TE_TARGET} ${COPY_TARGETS})
endfunction()
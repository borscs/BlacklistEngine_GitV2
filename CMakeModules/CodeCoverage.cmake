
find_program(GCOV_PATH gcov)
find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

set(COVERAGE_COMPILER_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE INTERNAL "")

set(CMAKE_CXX_FLAGS_COVERAGE
    ${COVERAGE_COMPILER_FLAGS}
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )

set(CMAKE_C_FLAGS_COVERAGE
    ${COVERAGE_COMPILER_FLAGS}
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )

set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )

set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )

mark_as_advanced(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE
)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Coverage")
    if(NOT GCOV_PATH)
        message(FATAL ERROR "gcov not found")
    endif()
    
    if(NOT LCOV_PATH)
        message(FATAL ERROR "lcov not found")
    endif()

    if(NOT GENHTML_PATH)
        message(FATAL ERROR "genhtml not found")
    endif()

    set(COVERAGE_OUTPUT_DIR ${CMAKE_BINARY_DIR}/coverage)

    add_custom_target(coverage
         # Capturing lcov counters and generating report
         COMMAND ${LCOV_PATH} --directory . --capture --gcov-tool ${GCOV_PATH} --output-file ${COVERAGE_OUTPUT_DIR}.info
         COMMAND ${LCOV_PATH} --remove ${COVERAGE_OUTPUT_DIR}.info '${CMAKE_BINARY_DIR}/*' 'test/*' '/usr/*' '/opt/*' --gcov-tool ${GCOV_PATH} --output-file ${COVERAGE_OUTPUT_DIR}.info.cleaned
         COMMAND ${GENHTML_PATH} -o ${COVERAGE_OUTPUT_DIR} ${COVERAGE_OUTPUT_DIR}.info.cleaned
         COMMAND ${CMAKE_COMMAND} -E remove ${COVERAGE_OUTPUT_DIR}.info ${COVERAGE_OUTPUT_DIR}.info.cleaned

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Processing code coverage counters and generating report."
    )

    # Show info where to find the report
	add_custom_command(TARGET coverage POST_BUILD
        COMMAND ;
        COMMENT "Open file://${COVERAGE_OUTPUT_DIR}/index.html in your browser to view the coverage report."
    )

    add_custom_target(zero_coverage
        ${LCOV_PATH} --gcov-tool ${GCOV_PATH} --directory . --zerocounters
        COMMENT "Resetting code coverage counters to zero."
    )

endif()

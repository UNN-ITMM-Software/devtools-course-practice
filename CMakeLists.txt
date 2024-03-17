cmake_minimum_required(VERSION 2.8.6)
project(DevTools)

enable_testing()

#
# Set configuration
#

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configurations" FORCE)
if(DEFINED CMAKE_BUILD_TYPE)
    set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES} )
endif()

if(CMAKE_GENERATOR MATCHES "Makefiles|Ninja" AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

option(COVERAGE "Build with coverage support" OFF)

#
# Setup output directories
#

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

foreach(cfg ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER "${cfg}" cfg)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_PDB_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
endforeach()

#
# Add compiler options: enable C++11, all warnings, fail on warnings
#
# cmake_policy(SET CMP0054 NEW)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror")
    if(COVERAGE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
    endif()
endif()

#
# Add Google Test
#

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
set(LIBRARY_DEPS "gtest")

#
# Cpplint support
#

find_package(PythonInterp)

if(PYTHON_EXECUTABLE)
    file(GLOB_RECURSE srcs_for_cpplint
        "${CMAKE_SOURCE_DIR}/modules/*.h"
        "${CMAKE_SOURCE_DIR}/modules/*.hpp"
        "${CMAKE_SOURCE_DIR}/modules/*.cpp"
        "${CMAKE_SOURCE_DIR}/modules/*.cxx")

    set(cpplint_out_files "")
    foreach(src_file ${srcs_for_cpplint})
        file(RELATIVE_PATH src_file_relative "${CMAKE_SOURCE_DIR}/modules" "${src_file}")

        get_filename_component(file_dir "${src_file_relative}" DIRECTORY)
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/cpplint.out/${file_dir}")

        set(cpplint_out_file "${CMAKE_BINARY_DIR}/cpplint.out/${src_file_relative}.cpplint.out")
        list(APPEND cpplint_out_files "${cpplint_out_file}")

        add_custom_command(OUTPUT "${cpplint_out_file}"
            COMMAND "${CMAKE_COMMAND}"
                    -D "FILE=${src_file}"
                    -D "OUT_FILE=${cpplint_out_file}"
                    -P "${CMAKE_SOURCE_DIR}/run_cpplint.cmake"
            MAIN_DEPENDENCY "${src_file}"
            DEPENDS "run_cpplint.cmake"
            COMMENT "Perform code analysis via cpplint for ${src_file_relative}"
            VERBATIM)
    endforeach()

    set_property(SOURCE ${cpplint_out_files} PROPERTY GENERATED TRUE)

    add_custom_target(cpplint
        DEPENDS ${cpplint_out_files}
        COMMENT "Perform code analysis via cpplint"
        SOURCES "run_cpplint.cmake")
endif()

#
# Include all modules
#

file(GLOB SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/modules/*")

foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()

#
# Cppcheck support
#

find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

if(CPPCHECK_EXECUTABLE)
    set(CPPCHECK_ARGS "")

    foreach(subdir ${SUBDIRS})
        if(EXISTS "${subdir}/include")
            list(APPEND CPPCHECK_ARGS "-I${subdir}/include")
            list(APPEND CPPCHECK_ARGS "-I${subdir}")
        endif()
    endforeach()

    list(APPEND CPPCHECK_ARGS "${CMAKE_CURRENT_SOURCE_DIR}/modules")

    add_custom_target(
        cppcheck "${CPPCHECK_EXECUTABLE}" "--enable=all" "--error-exitcode=1" "--check-config" "--suppress=missingIncludeSystem" "-itest" ${CPPCHECK_ARGS}
        COMMENT "Run cppcheck tool"
        VERBATIM)
endif()

#
# Report variables
#

message(STATUS "")
message(STATUS "General configuration for ${PROJECT_NAME}")
message(STATUS "==================================")
message(STATUS "")
message(STATUS "   Compiler:      ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message(STATUS "   Coverage:      ${COVERAGE}")
# message(STATUS "   Code coverage:     ${WITH_CODE_COVERAGE}")
message(STATUS "   Detected modules:")
foreach(subdir ${SUBDIRS})
    get_filename_component(DIR_NAME ${subdir} NAME)
    message(STATUS "    - ${DIR_NAME}")
endforeach()
message(STATUS "")

#
# Enable testing with CTest
#

enable_testing()

# function(test_function)
#   foreach(subdir ${SUBDIRS})
#       get_filename_component(DIR_NAME ${subdir} NAME)
#       message(STATUS "    - ${DIR_NAME}")
#   endforeach()
# endfunction(test_function)
#
# add_test(
#     NAME cpplint
#     COMMAND test_function()
# )

#
# Bugreport support
#

# if(PYTHON_EXECUTABLE)
#     add_test(NAME bugreport
#             COMMAND ${PYTHON_EXECUTABLE}
#             ${CMAKE_SOURCE_DIR}/3rdparty/bugreport.py)
# endif()

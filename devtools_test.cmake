#
# Include CTest Ext module
#

include("${CMAKE_CURRENT_LIST_DIR}/3rdparty/ctest-ext/ctest_ext.cmake")

#
# Check Pull Request Title
#

if(DEFINED ENV{TRAVIS_PULL_REQUEST})
    set(PULL_REQUEST_ID "$ENV{TRAVIS_PULL_REQUEST}")

    find_program(CURL_EXECUTABLE NAMES curl)

    if(CURL_EXECUTABLE)
        execute_process(
            COMMAND "${CURL_EXECUTABLE}" "https://api.github.com/repos/UNN-VMK-Software/devtools-course-practice/pulls/${PULL_REQUEST_ID}"
            OUTPUT_VARIABLE pr_info
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        if(pr_info MATCHES "\\\"title\\\": \\\"([^\r\n]*)\\\",\n")
            set(PULL_REQUEST_TITLE "${CMAKE_MATCH_1}")
        endif()
    endif()
endif()

if(DEFINED ENV{APPVEYOR_PULL_REQUEST_NUMBER})
    set(PULL_REQUEST_ID     "$ENV{APPVEYOR_PULL_REQUEST_NUMBER}")
    set(PULL_REQUEST_TITLE  "$ENV{APPVEYOR_PULL_REQUEST_TITLE}")
endif()

if(PULL_REQUEST_TITLE)
    ctext_ext_log_stage("Check pull request title")

    if(PULL_REQUEST_TITLE MATCHES ".* - Лабораторная работа #[0-9].*")
        message("${CTEST_EXT_TEXT_STYLE_BOLD_GREEN}SUCCESS: Valid title of the pull request: ${PULL_REQUEST_TITLE}${CTEST_EXT_TEXT_STYLE_RESET}")
    else()
        message("${CTEST_EXT_TEXT_STYLE_BOLD_RED}FAILURE: Invalid title of the pull request: ${PULL_REQUEST_TITLE}${CTEST_EXT_TEXT_STYLE_RESET}")
        message("${CTEST_EXT_TEXT_STYLE_BOLD_RED}Should be something like: Корняков - Лабораторная работа #1${CTEST_EXT_TEXT_STYLE_RESET}")
    endif()
endif()

#
# Initialize testing
#

set_ifndef(CTEST_PROJECT_NAME       "devtools-course-practice")

set_ifndef(CTEST_DASHBOARD_ROOT     "${CMAKE_CURRENT_LIST_DIR}/dashboard")
set_ifndef(CTEST_SOURCE_DIRECTORY   "${CMAKE_CURRENT_LIST_DIR}")

ctest_ext_init()

if(PULL_REQUEST_ID)
    set(CTEST_BUILD_NAME "${CTEST_BUILD_NAME}-PR#${PULL_REQUEST_ID}")
endif()

#
# Check supported targets and models
#

check_if_matches(CTEST_MODEL "^Experimental$" "^Nightly$" "^Coverage$" "^MemCheck$" "^CodeCheck$")

#
# Configure the testing model (set options, not specified by user, to default values)
#

if(CTEST_MODEL STREQUAL "Nightly")
    if(CTEST_COVERAGE_COMMAND)
        set_ifndef(CTEST_WITH_COVERAGE          TRUE)
        set_ifndef(CTEST_COVERAGE_TOOL          "CDASH")
    endif()

    if(CTEST_MEMORYCHECK_COMMAND)
        set_ifndef(CTEST_WITH_DYNAMIC_ANALYSIS  TRUE)
        set_ifndef(CTEST_DYNAMIC_ANALYSIS_TOOL  "CDASH")
    endif()

    set_ifndef(CTEST_WITH_SUBMIT                TRUE)
endif()

if(CTEST_MODEL STREQUAL "Coverage")
    check_vars_exist(CTEST_COVERAGE_COMMAND)

    set(CTEST_WITH_COVERAGE                     TRUE)
    set(CTEST_COVERAGE_TOOL                     "CDASH")

    set_ifndef(CTEST_WITH_SUBMIT                TRUE)
endif()

if(CTEST_MODEL STREQUAL "MemCheck")
    check_vars_exist(CTEST_MEMORYCHECK_COMMAND)

    set(CTEST_WITH_TESTS                        FALSE)

    set(CTEST_WITH_DYNAMIC_ANALYSIS             TRUE)
    set(CTEST_DYNAMIC_ANALYSIS_TOOL             "CDASH")

    set_ifndef(CTEST_WITH_SUBMIT                TRUE)
endif()

if(CTEST_MODEL STREQUAL "CodeCheck")
    set(CTEST_WITH_TESTS                        FALSE)
endif()

#
# Configure cmake options
#

if(CTEST_TARGET_SYSTEM MATCHES "^Windows")
    set_ifndef(CTEST_CMAKE_GENERATOR "Visual Studio 16 2019")
else()
    set_ifndef(CTEST_CMAKE_GENERATOR "Unix Makefiles")
endif()

set_ifndef(CTEST_CONFIGURATION_TYPE "Debug")

if(CTEST_WITH_COVERAGE)
    add_cmake_cache_entry("COVERAGE" TYPE "BOOL" "ON")
endif()

#
# Start testing
#

ctest_ext_start()

#
# Configure
#

ctest_ext_configure()

#
# Build
#

if(CTEST_MODEL STREQUAL "CodeCheck")
    ctest_ext_build(TARGETS "cpplint" "cppcheck")
else()
    ctest_ext_build()
endif()

#
# Test
#

ctest_ext_test()

#
# Coverage
#

ctest_ext_coverage(
    CDASH
        LABELS "Library;Application")

#
# MemCheck
#

ctest_ext_dynamic_analysis()

#
# Submit
#

ctest_ext_submit()

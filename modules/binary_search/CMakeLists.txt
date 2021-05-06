# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(TESTS       "test_${MODULE}")

# Include directory with public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add all submodules
add_subdirectory(test)

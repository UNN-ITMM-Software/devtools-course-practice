get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE  "${DIR_NAME}")
set(LIBRARY "lib_${MODULE}")
set(TESTS   "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)


include("CTestTests.txt")
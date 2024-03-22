execute_process(
    COMMAND "cpplint" "--filter=-runtime/references" "${FILE}"
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
    ERROR_VARIABLE error
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE)

if(NOT output STREQUAL "")
    message("${output}")
endif()
if(NOT error STREQUAL "")
    message("${error}")
endif()

if(NOT result EQUAL 0)
    message(FATAL_ERROR "cpplint failed with ${result} code")
endif()

file(WRITE "${OUT_FILE}" "${output}\n${error}\n")

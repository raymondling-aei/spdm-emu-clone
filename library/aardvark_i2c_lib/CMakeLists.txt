cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(${LIBSPDM_DIR}/include
                    ${SPDM_EMU_DIR}/include
)

SET(src_aardvark_i2c_lib
    aardvark.c
)

SET_SOURCE_FILES_PROPERTIES(aardvark.c PROPERTIES COMPILE_FLAGS -W3)

ADD_LIBRARY(aardvark_i2c_lib STATIC ${src_aardvark_i2c_lib})
if(CMAKE_GENERATOR MATCHES "^Visual Studio")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        STRING(REPLACE "/" "\\" DEST ${EXECUTABLE_OUTPUT_PATH}/Debug)
    else()
        STRING(REPLACE "/" "\\" DEST ${EXECUTABLE_OUTPUT_PATH}/Release)
    endif()
else()
    STRING(REPLACE "/" "\\" DEST ${EXECUTABLE_OUTPUT_PATH})
endif()

ADD_CUSTOM_COMMAND(TARGET aardvark_i2c_lib
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_CURRENT_SOURCE_DIR}/aardvark.dll"
                ${DEST})

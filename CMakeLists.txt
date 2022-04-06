cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project(arvcc)


option(ARVCC_BUILD_TESTS "GTest" OFF)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

if (UNIX)
    set(CMAKE_CXX_FLAGS "-pthread")
endif(UNIX)

# generate IR
if (ARVCC_IR_GEN)
    execute_process(
        
    #COMMAND sh build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()



function (arvcc_executable)
    cmake_parse_arguments(BIN "" "NAME" "COMPILER;INCLUDES;XLIBS" ${ARGN}) 


    set(BIN_INCLUDES
        PRIVATE

        compiler/include/
        ${BIN_INCLUDES}
    )


    set(BIN_COMPILER

        compiler/lib/Diag/Diagnostic.cpp
        compiler/lib/Driver/Driver.cpp
        compiler/lib/Option/OptTable.cpp
        compiler/tools/cc1_main.cpp
        ${BIN_COMPILER}
    )


    # added external libs
    set(BIN_XLIBS

        ${BIN_XLIBS}
    )

    add_executable(${BIN_NAME} ${BIN_COMPILER})
    target_include_directories(${BIN_NAME} ${BIN_INCLUDES})
    target_link_libraries(${BIN_NAME} ${BIN_XLIBS})
endfunction()

#add_subdirectory(third-party/)

arvcc_executable(
    NAME arvcc
    COMPILER compiler/tools/driver.cpp
)

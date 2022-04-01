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
    cmake_parse_arguments(BIN "" "NAME" "COMPILER;INCLUDES;LIBS" ${ARGN}) 


    set(BIN_INCLUDES
        PRIVATE


        ${BIN_INCLUDES}
    )


    set(BIN_COMPILER

        compiler/ir/ir.cpp compiler/ir/ir.h
        ${BIN_COMPILER}
    )

    set(BIN_LIBS

        ${BIN_LIBS}
    )

    add_executable(${BIN_NAME} ${BIN_COMPILER})
    target_include_directories(${BIN_NAME} ${BIN_INCLUDES})
    target_link_libraries(${BIN_NAME} ${BIN_LIBS})
endfunction()

#add_subdirectory(third-party/)

arvcc_executable(
    NAME arvcc
    COMPILER compiler/main.cpp    
)

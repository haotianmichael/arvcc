cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project(arvcc)


option(ARVCC_BUILD_TESTS "GTest" OFF)
option(ARVCC_ANTLR4_GEN "Use Antlr4 gen" ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

if (UNIX)
    set(CMAKE_CXX_FLAGS "-pthread")
endif(UNIX)

# generate parser
if (ARVCC_ANTLR4_GEN)
    execute_process(
        
    COMMAND sh build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()



function (arvcc_executable)
    cmake_parse_arguments(BIN "" "NAME" "SOURCES;INCLUDES;LIBS" ${ARGN}) 


    set(BIN_INCLUDES
        PRIVATE
        src/
        third-party/

        ${BIN_INCLUDES}
    )


    set(BIN_SOURCES
        src/parser/gen/ARLexer.cpp 
        src/parser/gen/ARParser.cpp 
        src/parser/gen/ARParserVisitor.cpp
        src/parser/gen/ARParserBaseVisitor.cpp

        src/ir/ir.cpp
        src/ir/ir.h
        ${BIN_SOURCES}
    )

    set(BIN_LIBS
        antlr4_static 
        ${BIN_LIBS}
    )

    add_executable(${BIN_NAME} ${BIN_SOURCES})
    target_include_directories(${BIN_NAME} ${BIN_INCLUDES})
    target_link_libraries(${BIN_NAME} ${BIN_LIBS})
endfunction()

add_subdirectory(third-party/antlr_runtime)

arvcc_executable(
    NAME arvcc
    SOURCES src/main.cpp    
)



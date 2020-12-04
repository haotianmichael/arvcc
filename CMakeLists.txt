cmake_minimum_required(VERSION 3.15)
project(arvcc)


option(ARVCC_BUILD_TESTS "GTest" ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

# generate parser
if (PARSER_ON)
    execute_process(
        
    COMMAND sh build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()



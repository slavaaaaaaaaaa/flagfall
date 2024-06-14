################################################################################
## cmake setup
cmake_minimum_required(VERSION 3.15)
##
################################################################################

################################################################################
## Project setup
set(PROJECT_NAME flagfall)

# Versioning
project(${PROJECT_NAME} VERSION 0.1.0.0 LANGUAGES C CXX)

################################################################################
## Build Options (Turn ON or OFF as needed)
option(BUILD_TESTS "Option to build unit tests" ON)  # No tests currently set
option(BUILD_UNIVERSAL_BINARY "Option to build universal binary (x86_64 and arm64)" ON)
option(BUILD_INTEL "Option to build x86_64" OFF)
option(BUILD_ARM "Option to build arm64" OFF)
################################################################################

################################################################################
## Generic build setup
include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sets up link-time optimization if supported by compiler
message(STATUS "Checking for link-time optimization (LTO)")
include(CheckIPOSupported)
check_ipo_supported(RESULT lto)
message(STATUS "LTO supported = ${lto}")
# Example of usage on build targets
#if(lto)
#  set_target_properties(ColorMeter PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
#endif()

## Defaults to arm64 on Apple.
if(APPLE AND NOT DEFINED CMAKE_OSX_ARCHITECTURES)
    set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "Default architecture for macOS")
    if(BUILD_INTEL)
        set(CMAKE_OSX_ARCHITECTURES "x86_64" FORCE)
    elseif(BUILD_ARM)
        set(CMAKE_OSX_ARCHITECTURES "arm64" FORCE)
    elseif(BUILD_UNIVERSAL_BINARY)
        set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" FORCE)
    endif()
endif()
################################################################################



################################################################################
# flagfall
set(
    SOURCE_FILES 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/board.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/board.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/king.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/king.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/pawn.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/pawn.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/queen.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/queen.h 
        
        )

add_library(${PROJECT_NAME} "" )
add_library(slavalib::flagfall ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

################################################################################


################################################################################
# test programs
if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
################################################################################

cmake_minimum_required(VERSION 3.12)
project(CMake_Tutorial C)

set(CMAKE_C_STANDARD 99)
set(CMake_Tutorial_VERSION_MAJOR 1)
set(CMake_Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/CMake_Tutorial_Config.h.in"
        "${PROJECT_BINARY_DIR}/CMake_Tutorial_Config.h"
)

# add the binary tree to the search path for include files
# so that we will find CMake_Tutorial_Config.h
include_directories("{PROJECT_BINARY_DIR}")

# add the executable
add_executable(CMake_Tutorial tutorial.c)
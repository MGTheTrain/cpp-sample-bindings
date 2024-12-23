cmake_minimum_required(VERSION 3.10)
set(TARGET cpp-opengl-renderer)
project(${TARGET})   
set(CMAKE_CXX_STANDARD 11)

option(BUILD_LIB "Compile module source files for static and shared libraries" ON)
option(BUILD_TEST "Compile source files for test executable and link compiled libraries" ON)
option(BUILD_APP "Compile source file of main executable and link compiled libraries" ON) 

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(BUILD_TEST)
    include(CTestConfig)
endif()

add_subdirectory(modules)
add_subdirectory(apps)
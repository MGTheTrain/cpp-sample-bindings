cmake_minimum_required(VERSION 3.10)

set(TARGET core)
project(${TARGET})

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(CORE_SRC 
    math-utils.cpp
)   

add_library(${TARGET} STATIC ${CORE_SRC})
add_library(${TARGET}_wrapper SHARED ${CORE_SRC}) # required for bindings

install(TARGETS ${TARGET} ${TARGET}_wrapper)
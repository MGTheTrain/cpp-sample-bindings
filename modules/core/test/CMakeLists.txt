cmake_minimum_required(VERSION 3.10)


set(TESTING_TARGET core_test)
project(${TESTING_TARGET})

add_definitions(-DMGTT_CORE_TEST)

enable_testing()
find_package(GTest CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include_directories(${GTEST_INCLUDE_DIRS} 
                    ../include
)
set(CORE_TEST_SRC 
    entrypoint.cpp
    math-utils-test.cpp)                        
add_executable(${TESTING_TARGET} ${CORE_TEST_SRC})
target_link_libraries(${TESTING_TARGET} PRIVATE GTest::gtest GTest::gtest_main core)
add_test(NAME ${TESTING_TARGET} COMMAND $<TARGET_FILE:${TESTING_TARGET}>)

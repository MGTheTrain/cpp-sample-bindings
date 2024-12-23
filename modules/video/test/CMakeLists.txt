cmake_minimum_required(VERSION 3.10)


set(TESTING_TARGET video_test)
project(${TESTING_TARGET})

add_definitions(-DMGTT_VIDEO_TEST)

enable_testing()
find_package(GTest CONFIG REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} 
                    ../include
)
set(VIDEO_TEST_SRC 
    entrypoint.cpp
    video-test.cpp)                        
add_executable(${TESTING_TARGET} ${VIDEO_TEST_SRC})
if(WIN32)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/)
elseif(APPLE OR UNIX)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)
else()
    message(WARNING "Unsupported platform")
endif()
target_link_libraries(${TESTING_TARGET} PRIVATE GTest::gtest GTest::gtest_main video)
add_test(NAME ${TESTING_TARGET} COMMAND $<TARGET_FILE:${TESTING_TARGET}>)

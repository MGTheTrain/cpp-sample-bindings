cmake_minimum_required(VERSION 3.10)
set(TARGET audio_player)
project(${TARGET})

add_definitions(-DAUDIO_PLAYER)

include_directories(../include
                    ../../../modules/audio/include
)
set(AUDIO_PLAYER_SRC audio-player.cpp)                        

add_executable(${TARGET} ${AUDIO_PLAYER_SRC})
if(WIN32)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/)
elseif(APPLE OR UNIX)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)
else()
    message(WARNING "Unsupported platform")
endif()
target_link_libraries(${TARGET} PRIVATE audio)

install(TARGETS ${TARGET})
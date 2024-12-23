cmake_minimum_required(VERSION 3.10)
set(TARGET video_player)
project(${TARGET})

add_definitions(-DVIDEO_PLAYER)

find_package(FFMPEG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

include_directories(../include
                    ../../../modules/video/include
                    ${FFMPEG_INCLUDE_DIRS}
)
set(VIDEO_PLAYER_SRC video-player.cpp)                        

add_executable(${TARGET} ${VIDEO_PLAYER_SRC})
if(WIN32)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/)
elseif(APPLE OR UNIX)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../../../assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)
else()
    message(WARNING "Unsupported platform")
endif()

target_link_libraries(${TARGET} PRIVATE video ${FFMPEG_LIBRARIES} SDL2::SDL2)

install(TARGETS ${TARGET})
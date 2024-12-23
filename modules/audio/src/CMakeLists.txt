cmake_minimum_required(VERSION 3.10)

set(TARGET audio)
project(${TARGET})

find_package(portaudio CONFIG REQUIRED)
find_package(SndFile CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(AUDIO_SRC 
    audio.cpp
)   

add_library(${TARGET} STATIC ${AUDIO_SRC})
add_library(${TARGET}_wrapper SHARED ${AUDIO_SRC}) # required for bindings

if(APPLE)
    target_link_libraries(${TARGET} SndFile::sndfile portaudio_static)
    target_link_libraries(${TARGET}_wrapper SndFile::sndfile portaudio_static)
else()
    target_link_libraries(${TARGET} SndFile::sndfile portaudio)
    target_link_libraries(${TARGET}_wrapper SndFile::sndfile portaudio)
endif()
install(TARGETS ${TARGET} ${TARGET}_wrapper)
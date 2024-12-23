cmake_minimum_required(VERSION 3.10)

set(TARGET video)
project(${TARGET})

find_package(FFMPEG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../include
                    ${FFMPEG_INCLUDE_DIRS})

set(VIDEO_SRC 
    video.cpp
)   

add_library(${TARGET} STATIC ${VIDEO_SRC})
target_link_libraries(${TARGET} PRIVATE ${FFMPEG_LIBRARIES} SDL2::SDL2)

# add_library(${TARGET}_wrapper SHARED ${VIDEO_SRC}) # required for bindings
# target_link_libraries(${TARGET}_wrapper PRIVATE ${FFMPEG_LIBRARIES} SDL2::SDL2)

# install(TARGETS ${TARGET} ${TARGET}_wrapper)
install(TARGETS ${TARGET})
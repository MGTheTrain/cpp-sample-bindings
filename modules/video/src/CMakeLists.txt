# The MIT License
#
# Copyright (c) 2024 MGTheTrain
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.10)

set(TARGET video)
project(${TARGET})

find_package(FFMPEG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(VIDEO_SRC 
    video.cpp
)   

add_library(${TARGET} STATIC ${VIDEO_SRC})
target_include_directories(${TARGET} PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_directories(${TARGET} PRIVATE ${FFMPEG_LIBRARY_DIRS})
target_link_libraries(${TARGET} PRIVATE ${FFMPEG_LIBRARIES})
target_link_libraries(${TARGET} PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)

add_library(${TARGET}_wrapper SHARED ${VIDEO_SRC}) # required for bindings
target_include_directories(${TARGET}_wrapper PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_directories(${TARGET}_wrapper PRIVATE ${FFMPEG_LIBRARY_DIRS})
target_link_libraries(${TARGET}_wrapper PRIVATE ${FFMPEG_LIBRARIES})
target_link_libraries(${TARGET}_wrapper PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)

install(TARGETS ${TARGET})
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

target_link_libraries(${TARGET} SndFile::sndfile portaudio)
target_link_libraries(${TARGET}_wrapper SndFile::sndfile portaudio)

install(TARGETS ${TARGET})
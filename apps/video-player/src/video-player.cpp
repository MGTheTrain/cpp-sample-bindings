// The MIT License
//
// Copyright (c) 2024 MGTheTrain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifdef VIDEO_PLAYER
#include <video-player.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <video_file>\n", argv[0]);
        return -1;
    }

    const char* videoFileName = argv[1];

    if (!initVideoPlayer()) {
        std::cerr << "Failed to initialize video player\n";
        return -1;
    }

    if (!loadVideo(videoFileName)) {
        std::cerr << "Failed to load video: " << videoFileName << "\n";
        closeVideoPlayer();
        return -1;
    }

    playVideo();

    closeVideoPlayer();

    return 0;
}
#endif
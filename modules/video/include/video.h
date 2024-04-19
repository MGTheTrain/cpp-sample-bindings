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

#pragma once

#include <iostream>

#ifdef __cplusplus
extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#endif

/**
 * @brief The VideoPlayer struct represents a video player.
 */
struct VideoPlayer {
  /**
   * @brief Constructs a new VideoPlayer object.
   */
  VideoPlayer();

  AVFormatContext* formatContext;
  AVCodecParameters* codecParameters;
  AVCodecContext* codecContext;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  struct SwsContext* swsContext;
  AVFrame* frame;
  int videoStream;
  AVRational timeBase;
  double frameDuration;
};

/**
 * @brief Initializes the video player.
 *
 * @param player Reference to the VideoPlayer object.
 * @return True if initialization succeeds, false otherwise.
 */
bool initVideoPlayer(VideoPlayer& player);

/**
 * @brief Loads a video file into the video player.
 *
 * @param player Reference to the VideoPlayer object.
 * @param filename The path to the video file.
 * @return True if loading succeeds, false otherwise.
 */
bool loadVideo(VideoPlayer& player, const char* filename);

/**
 * @brief Starts playing the loaded video.
 *
 * @param player Reference to the VideoPlayer object.
 */
void playVideo(VideoPlayer& player);

/**
 * @brief Closes the video player and releases resources.
 *
 * @param player Reference to the VideoPlayer object.
 */
void closeVideoPlayer(VideoPlayer& player);

#ifdef __cplusplus
}
#endif
#pragma once

#include <iostream>

#ifdef __cplusplus
extern "C" {
#define SDL_MAIN_HANDLED
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
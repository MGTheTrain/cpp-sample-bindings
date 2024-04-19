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

#include <video.h>

bool initVideoPlayer(VideoPlayer& player) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << "\n";
    return false;
  }

  if (avformat_network_init() < 0) {
    std::cerr << "Failed to initialize FFmpeg network\n";
    return false;
  }

  return true;
}

bool loadVideo(VideoPlayer& player, const char* filename) {
  if (avformat_open_input(&player.formatContext, filename, NULL, NULL) != 0) {
    std::cerr << "Couldn't open video file\n";
    return false;
  }

  if (avformat_find_stream_info(player.formatContext, NULL) < 0) {
    std::cerr << "Couldn't find stream information\n";
    return false;
  }

  player.videoStream = -1;
  for (int i = 0; i < player.formatContext->nb_streams; i++) {
    if (player.formatContext->streams[i]->codecpar->codec_type ==
        AVMEDIA_TYPE_VIDEO) {
      player.videoStream = i;
      break;
    }
  }

  if (player.videoStream == -1) {
    std::cerr << "Couldn't find a video stream\n";
    return false;
  }

  player.codecParameters =
      player.formatContext->streams[player.videoStream]->codecpar;
  const AVCodec* codec = avcodec_find_decoder(player.codecParameters->codec_id);
  if (!codec) {
    std::cerr << "Unsupported codec\n";
    return false;
  }

  player.codecContext = avcodec_alloc_context3(codec);
  if (avcodec_parameters_to_context(player.codecContext,
                                    player.codecParameters) < 0) {
    std::cerr << "Failed to copy codec parameters to codec context\n";
    return false;
  }

  if (avcodec_open2(player.codecContext, codec, NULL) < 0) {
    std::cerr << "Failed to open codec\n";
    return false;
  }

  player.window = SDL_CreateWindow(
      "Video Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      player.codecContext->width, player.codecContext->height,
      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (!player.window) {
    std::cerr << "Failed to create SDL window: " << SDL_GetError() << "\n";
    return false;
  }

  player.renderer =
      SDL_CreateRenderer(player.window, -1, SDL_RENDERER_ACCELERATED);
  if (!player.renderer) {
    std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << "\n";
    return false;
  }

  player.texture = SDL_CreateTexture(
      player.renderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING,
      player.codecContext->width, player.codecContext->height);
  if (!player.texture) {
    std::cerr << "Failed to create SDL texture: " << SDL_GetError() << "\n";
    return false;
  }

  player.swsContext =
      sws_getContext(player.codecContext->width, player.codecContext->height,
                     player.codecContext->pix_fmt, player.codecContext->width,
                     player.codecContext->height, AV_PIX_FMT_YUV420P,
                     SWS_BILINEAR, NULL, NULL, NULL);
  if (!player.swsContext) {
    std::cerr << "Failed to create SwsContext\n";
    return false;
  }

  player.timeBase =
      player.formatContext->streams[player.videoStream]->time_base;
  player.frameDuration = av_q2d(player.timeBase);

  return true;
}

void playVideo(VideoPlayer& player) {
  AVPacket packet;
  Uint32 previousFrameTime = SDL_GetTicks();

  while (av_read_frame(player.formatContext, &packet) >= 0) {
    if (packet.stream_index == player.videoStream) {
      if (avcodec_send_packet(player.codecContext, &packet) < 0) {
        std::cerr << "Error sending a packet for decoding\n";
        continue;
      }

      if (avcodec_receive_frame(player.codecContext, player.frame) == 0) {
        sws_scale(player.swsContext, player.frame->data, player.frame->linesize,
                  0, player.frame->height, player.frame->data,
                  player.frame->linesize);

        SDL_UpdateYUVTexture(player.texture, nullptr, player.frame->data[0],
                             player.frame->linesize[0], player.frame->data[1],
                             player.frame->linesize[1], player.frame->data[2],
                             player.frame->linesize[2]);
        SDL_RenderClear(player.renderer);
        SDL_RenderCopy(player.renderer, player.texture, nullptr, nullptr);
        SDL_RenderPresent(player.renderer);

        Uint32 currentFrameTime = SDL_GetTicks();
        Uint32 elapsedTime = currentFrameTime - previousFrameTime;
        previousFrameTime = currentFrameTime;

        int desiredDelay = (int)(player.frameDuration * 1000) - elapsedTime;

        if (desiredDelay > 0) {
          SDL_Delay(desiredDelay);
        }
      }
    }
    av_packet_unref(&packet);
  }
}

void closeVideoPlayer(VideoPlayer& player) {
  SDL_DestroyTexture(player.texture);
  SDL_DestroyRenderer(player.renderer);
  SDL_DestroyWindow(player.window);
  SDL_Quit();

  av_frame_free(&player.frame);
  avcodec_close(player.codecContext);
  avformat_close_input(&player.formatContext);
  avformat_network_deinit();
}
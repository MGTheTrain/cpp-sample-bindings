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

bool initVideoPlayer() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << "\n";
    return false;
  }

  av_register_all();
  if (avformat_network_init() < 0) {
    std::cerr << "Failed to initialize FFmpeg network\n";
    return false;
  }

  return true;
}

bool loadVideo(const char* filename) {
  if (avformat_open_input(&formatContext, filename, NULL, NULL) != 0) {
    std::cerr << "Couldn't open video file\n";
    return false;
  }

  if (avformat_find_stream_info(formatContext, NULL) < 0) {
    std::cerr << "Couldn't find stream information\n";
    return false;
  }

  videoStream = -1;
  for (int i = 0; i < formatContext->nb_streams; i++) {
    if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
      videoStream = i;
      break;
    }
  }

  if (videoStream == -1) {
    std::cerr << "Couldn't find a video stream\n";
    return false;
  }

  codecParameters = formatContext->streams[videoStream]->codecpar;
  codec = avcodec_find_decoder(codecParameters->codec_id);
  if (!codec) {
    std::cerr << "Unsupported codec\n";
    return false;
  }

  codecContext = avcodec_alloc_context3(codec);
  if (avcodec_parameters_to_context(codecContext, codecParameters) < 0) {
    std::cerr << "Failed to copy codec parameters to codec context\n";
    return false;
  }

  if (avcodec_open2(codecContext, codec, NULL) < 0) {
    std::cerr << "Failed to open codec\n";
    return false;
  }

  window = SDL_CreateWindow("Video Player", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, codecContext->width,
                            codecContext->height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (!window) {
    std::cerr << "Failed to create SDL window: " << SDL_GetError() << "\n";
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << "\n";
    return false;
  }

  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_YV12,
                              SDL_TEXTUREACCESS_STREAMING, codecContext->width,
                              codecContext->height);
  if (!texture) {
    std::cerr << "Failed to create SDL texture: " << SDL_GetError() << "\n";
    return false;
  }

  swsContext = sws_getContext(codecContext->width, codecContext->height,
                              codecContext->pix_fmt, codecContext->width,
                              codecContext->height, AV_PIX_FMT_YUV420P,
                              SWS_BILINEAR, NULL, NULL, NULL);
  if (!swsContext) {
    std::cerr << "Failed to create SwsContext\n";
    return false;
  }

  timeBase = formatContext->streams[videoStream]->time_base;
  frameDuration = av_q2d(timeBase);

  return true;
}

void playVideo() {
  AVPacket packet;
  Uint32 previousFrameTime = SDL_GetTicks();

  while (av_read_frame(formatContext, &packet) >= 0) {
    if (packet.stream_index == videoStream) {
      if (avcodec_send_packet(codecContext, &packet) < 0) {
        std::cerr << "Error sending a packet for decoding\n";
        continue;
      }

      if (avcodec_receive_frame(codecContext, frame) == 0) {
        sws_scale(swsContext, frame->data, frame->linesize, 0, frame->height,
                  frame->data, frame->linesize);

        SDL_UpdateYUVTexture(texture, nullptr, frame->data[0],
                             frame->linesize[0], frame->data[1],
                             frame->linesize[1], frame->data[2],
                             frame->linesize[2]);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        Uint32 currentFrameTime = SDL_GetTicks();
        Uint32 elapsedTime = currentFrameTime - previousFrameTime;
        previousFrameTime = currentFrameTime;

        int desiredDelay = (int)(frameDuration * 1000) - elapsedTime;

        if (desiredDelay > 0) {
          SDL_Delay(desiredDelay);
        }
      }
    }
    av_packet_unref(&packet);
  }
}

void closeVideoPlayer() {
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  av_frame_free(&frame);
  avcodec_close(codecContext);
  avformat_close_input(&formatContext);
  avformat_network_deinit();
}